#include <iostream>
#include <functional>
#include <fstream>
#include <thread>
#include <vector>
#include "solver.h"
#include "import.h"
#include "namegen.h"
#include "righthand.h"
#include "tremaux.h"
#include "gaston.h"

/** ctor takes the path to the maze and graphic mode */
Solver::Solver(std::string filepath, bool right, bool tremaux, bool gaston, bool graphic)
    : filepath(filepath), graphic(graphic) {
  /** load the maze */
  this->load_maze();
  /** set up bots */
  this->setup_bots(right, tremaux, gaston);
};

/** load the maze */
void Solver::load_maze() {
  /** get a importer */
  auto import = std::make_shared<Import>();
  /** convert the file */
  auto converted = import->convert(this->filepath);
  /** create maze from file */
  this->laby = std::make_shared<Labyrinth>(converted);
}

/** set up the bots */
void Solver::setup_bots(bool right, bool tremaux, bool gaston) {
  /** namegenerator for bot names */
  auto namegen = std::make_shared<Namegen>();
  /** make three bots with different algorithms */
  if (right) {
    this->bots.push_back(std::make_shared<Righthand>(this->laby, namegen->get_name()));
  }
  if (tremaux) {
    this->bots.push_back(std::make_shared<Tremaux>(this->laby, namegen->get_name()));
  }
  if (gaston) {
    this->bots.push_back(std::make_shared<Gaston>(this->laby, namegen->get_name()));
  }
  if(this->bots.empty()) {
    this->bots.push_back(std::make_shared<Righthand>(this->laby, namegen->get_name()));
  }
}

/** solve the maze in threads */
void Solver::solve() {
  std::vector<std::thread> threads;
  /** release the bots */
  for(auto &bot : this->bots) {
    /** lambda expression which calls the find_exit function of the bot */
    threads.push_back(std::thread([&](std::shared_ptr<Bot> bot) { bot->find_exit(); }, bot));
  }
  /** join the three bots */
  for(auto &thr : threads) {
    thr.join();
  }
}

/** print the maze */
void Solver::print_maze() const {
  std::cout << "Entry at: x: " << this->laby->get_entry().x << " y: " << this->laby->get_entry().y
            << std::endl;
  std::cout << "Exit at: x: " << this->laby->get_exit().x << " y: " << this->laby->get_exit().y
            << std::endl;
  std::cout << "            111111111122222222223333333333444444444455555555556666666666"
            << std::endl;
  std::cout << "  0123456789012345678901234567890123456789012345678901234567890123456789"
            << std::endl;
  this->laby->print_maze();
}

/** print the result */
void Solver::print_result() const {
  unsigned int all_solved = 0;
  for (auto bot : this->bots) {
    all_solved += bot->is_solved();
  }

  /** check if all bots have solved the maze */
  if (all_solved != this->bots.size()) {
    std::cerr << "Error: "
              << "Couldn't solve the maze." << std::endl;
    exit(EXIT_FAILURE);
  } else {
    /** no graphic mode */
    if (!this->graphic) {
      for (auto bot : this->bots) {
        bot->print_history();
        std::cout << bot->get_name() << " of the type " << bot->get_type() << " solved the maze in "
                  << bot->get_step_counter() << " steps." << std::endl;
      }
    } else {
      /** graphic mode */
      for (auto bot : this->bots) {
        std::cout << bot->get_name() << " of the type " << bot->get_type() << " solved the maze in "
                  << bot->get_step_counter() << " steps." << std::endl;
        this->laby->print_maze(bot->get_history());
      }
    }
  }
}
