#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Item {
  private:
    std::string itemName;
  public:
    Item() = default;
    Item(std::string itemName) {this->itemName = itemName;}
    std::string getName() {
      return itemName;
    }
};

class Room {
  public:
    Item item1,item2,item3,item4,item5;
    std::string description;
    // Map to connect rooms as exits:- exit from room to room
    std::map<std::string, Room*> exits;
    std::vector<Item> itemList;
    
    Room(std::string description) {this->description = description;}

    void getItems() {
      for(int i = 0; i < itemList.size(); i++) {
        std::cout << itemList[i].getName() << std::endl;
      }
    }
};

class Player {
  public:
    Room* currentRoom; 
    std::vector<Item> inventory;

    Player(Room* currentRoom) {this->currentRoom = currentRoom;}    

    void listInventory() {
      for(int i = 0; i < inventory.size(); i++) {
        std::cout << inventory[i].getName() << std::endl;
      }
    }
    
};

class Game {
  private:
    Player player;
    std::vector<Room> rooms;
    std::map<std::string, Item> mapItems;
  public:
    Game() : player(&rooms[0]) {
      

      rooms = {
        // Defining room description
        Room("You're in your cozy cottage. You have a front door and a back door."),   // 0
        Room("You're in your back garden. There is a fence north."),                   // 1
        Room("This is the town hall. There is a northern exit and an eastern exit."),  // 2
        Room("You're in an abandoned coal mine. Go north or exit?"),                   // 3
        Room("You're deeper inside the cave. Proceed or live another day?"),           // 4
        Room("This is the beach. People love this place."),                            // 5
        Room("You're in the town's park. You can rest or go north."),                  // 6
        Room("You were slain by a spider :D"),                                         // 7
        Room("You put your feet in the cold water. Go deeper?"),                       // 8                                                                 
        Room("You're in a very dark forest. Go north or return before it's too late?"),// 9
        Room("You got lost in the forest :(")                                          // 10
      };

      rooms[0].item1 = Item("Flashlight"); 
      rooms[0].item2 = Item("Watch");
      rooms[0].item3 = Item("Knife");
      rooms[1].item1 = Item("Shovel");
      rooms[2].item1 = Item("Important Papers");
      rooms[2].item2 = Item("Key");

      rooms[0].itemList.push_back(rooms[0].item1);
      rooms[0].itemList.push_back(rooms[0].item2);
      rooms[0].itemList.push_back(rooms[0].item3);
      rooms[1].itemList.push_back(rooms[1].item1);
      rooms[2].itemList.push_back(rooms[2].item1);
      rooms[2].itemList.push_back(rooms[2].item2);

      rooms[0].exits["north"] = &rooms[2];
      rooms[0].exits["south"] = &rooms[1];
      rooms[1].exits["south"] = &rooms[0];
      rooms[1].exits["north"] = &rooms[3];
      rooms[2].exits["north"] = &rooms[6];
      rooms[2].exits["east"]  = &rooms[5];
      rooms[2].exits["south"] = &rooms[0];
      rooms[3].exits["north"] = &rooms[4];
      rooms[3].exits["south"] = &rooms[1];
      rooms[4].exits["south"] = &rooms[0];
      rooms[4].exits["north"] = &rooms[7];
      rooms[5].exits["north"] = &rooms[8];
      rooms[5].exits["south"] = &rooms[2];
      rooms[6].exits["north"] = &rooms[9];
      rooms[9].exits["north"] = &rooms[10];

      
      
      player = Player(&rooms[0]);     
    }
    
    void play() {
      std::string input;
      std::cout << player.currentRoom->description << std::endl;
       while(true) {
        std::cout << "go/do : ";
        std::getline(std::cin, input);
        if(input == "exit") {
          std::cout << "Goodbye :)" << std::endl;
          break;
        } else if(input == "look") {
          std::cout << player.currentRoom->description << std::endl;
        } else if(input == "help") {
          std::cout << "-------------------------------------------" << std::endl;
          std::cout << "Use north, south, east, west for navigation." << std::endl;
          std::cout << "More actions coming soon!" << std::endl;
          std::cout << "-------------------------------------------" << std::endl;
        } else if(player.currentRoom->exits.find(input) != player.currentRoom->exits.end()) {
          player.currentRoom = player.currentRoom->exits[input];
            if(player.currentRoom == &rooms[7] || player.currentRoom == &rooms[10]) {
              std::cout << player.currentRoom->description << std::endl;
              std::cout << "Goodbye." << std::endl;
              break;
            }
          std::cout << player.currentRoom->description << std::endl;
        } else if(input == "show items") {
          std::cout << "-------------------------------------------" << std::endl;
          player.currentRoom->getItems();
          std::cout << "-------------------------------------------" << std::endl;
        } else if(input == "show inventory") {
          player.listInventory();
        }
        for(int i = 0; i < player.currentRoom->itemList.size(); i++) {
          if(input == player.currentRoom->itemList[i].getName()) {
            player.inventory.push_back(player.currentRoom->itemList[i]);
            std::cout << "Added " << player.currentRoom->itemList[i].getName() << " to your inventory." << std::endl;
          }
        }
      }
      
    } 
};



int main() {
  Game game;
  game.play();
  
  return 0;
}
