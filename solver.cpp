#include <iostream>
#include <functional>
#include <thread>
#include "solver.h"
#include "import.h"
#include "namegen.h"
#include "righthand.h"
#include "tremaux.h"

Solver::Solver(std::string filepath) : filepath(filepath) {
  this->load_labyrinth();
  this->setup_bots();
};

void Solver::load_labyrinth() {
  auto import = std::make_shared<Import>();
  auto converted = import->convert(this->filepath);
  this->laby = std::make_shared<Labyrinth>(converted);
}

void Solver::setup_bots() {
  auto namegen = std::make_shared<Namegen>();
  this->bots[0] = std::make_shared<Righthand>(this->laby, namegen->get_name());
  this->bots[1] = std::make_shared<Righthand>(this->laby, namegen->get_name());
  this->bots[2] = std::make_shared<Tremaux>(this->laby, namegen->get_name());
}

void Solver::solve() {
  std::cout << "Entry at: x: " << this->laby->get_entry().x << " y: " << this->laby->get_entry().y
            << std::endl;
  std::cout << "Exit at: x: " << this->laby->get_exit().x << " y: " << this->laby->get_exit().y
            << std::endl;
  std::cout << "            111111111122222222223333333333444444444455555555556666666666"
            << std::endl;
  std::cout << "  0123456789012345678901234567890123456789012345678901234567890123456789"
            << std::endl;
  this->laby->print_maze();
  auto exit_finder = [&](std::shared_ptr<Bot> bot) { bot->find_exit(); };
  std::thread bot0(exit_finder, bots[0]);
  std::thread bot1(exit_finder, bots[1]);
  std::thread bot2(exit_finder, bots[2]);
  bot0.join();
  bot1.join();
  bot2.join();
  for (auto bot : this->bots) {
    bot->print_history();
    std::cout << bot->get_name() << " of the type " << bot->get_type() << std::endl;
  }
}
