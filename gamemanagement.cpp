#include <algorithm>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class InvalidNumberOfPlayers : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid number of players for the chosen game.";
    }
};
class Player {
public:
  string name;

  Player(string name) { this->name = name; }
};
class Team {
public:
  string name;
  vector<Player> players;

  void addPlayer(Player player) { this->players.push_back(player); }
  void displayTeamName() { cout << name << endl; }

  void displayTeamDetails() {
    cout << "Team: " << name << endl;
    cout << "Players: " << endl;
    for (Player player : players) {
      cout << player.name << endl;
    }
    cout << endl;
  }
  void play(Team t1, Team t2) {
    // play the tournament
    t1.displayTeamName();
    cout << " V/S " << endl;
    t2.displayTeamName();
  }
  void declareWinner(Team t1, Team t2) {
    // declare the winner of the tournament
    int score1, score2;
    cout << "enter the score of";
    t1.displayTeamName();
    cin >> score1;
    cout << "enter the score of";
    t2.displayTeamName();
    cin >> score2;

    if (score1 > score2) {
      t1.displayTeamName();
      cout << "is the winner" << endl;
    } else if (score1 < score2) {
      t2.displayTeamName();
      cout << "is the winner" << endl;
    } else if (score1 == score2) {
      cout << "the match is draw between the teams ";
      t1.displayTeamName();
      cout << " and ";
      t2.displayTeamName();
    }
  }
};
// Here there are two classes players and team which are linked to class games
// using composition Relationship
class Game {
public:
  int numberOfTeams;
  int numberOfRounds;
  Team team;
  Game(int numberOfTeams, int numberOfRounds) {

    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  // pure virtual functions and abstract class
  virtual void addPlayer(Player player) = 0;
  virtual void play(Team t1, Team t2) = 0;
  virtual void declareWinner(Team t1, Team t2) = 0;
  virtual void generateMatches(vector<Team> teams) = 0;
  virtual bool checkValidTeams(vector<Team> teams) = 0;
};

class Chess : public Game {
public:
  int numberOfTeams;
  int numberOfRounds;
  Team team;

  Chess(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  // in chess there will be only two persons in each team so we need to check
  // the number of members in the team then input the players in the team

  bool checkValidTeams(vector<Team> teams) {
    // Check if there are two or fewer players from each team
    for (Team team : teams) {
      if (team.players.size() < 2 && team.players.size() == 0) {
        return false;
      }
    }
    return true;
  }

  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          cout << "Round  " << k << endl;
          play(teams[i], teams[j]);
          cout << "Round " << k << " winner" << endl;
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};
class Cricket : public Game {
public:
  int numberOfTeams;
  int numberOfRounds;
  Team team;

public:
  Cricket(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  bool checkValidTeams(vector<Team> teams) {

    for (Team team : teams) {
      if (team.players.size() < 11 && team.players.size() == 0 &&
          team.players.size() > 11) {
        return false;
      }
    }
    return true;
  }
  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          play(teams[i], teams[j]);
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};
class WrestlingGame : public Game {
public:
  int numberOfTeams;
  int numberOfRounds;
  Team team;

public:
  WrestlingGame(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds =
        numberOfRounds; // number of periods in wrestling usually 2 or 3
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  bool checkValidTeams(vector<Team> teams) {

    for (Team team : teams) {
      if (team.players.size() < 1 && team.players.size() == 0) {
        return false;
      }
    }
    return true;
  }
  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          cout << "period  " << k << endl;
          play(teams[i], teams[j]);
          cout << "period " << k << " winner" << endl;
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};
class Badminton : public Game {
public:
  int numberOfTeams;
  int numberOfRounds;
  Team team;

public:
  Badminton(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  // in chess there will be only two persons in each team so we need to check
  // the number of members in the team then input the players in the team

  bool checkValidTeams(vector<Team> teams) {
    // Check if there are two or fewer players from each team
    for (Team team : teams) {
      if (team.players.size() < 3 && team.players.size() == 0) {
        return false;
      }
    }
    return true;
  }

  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          cout << "Round  " << k << endl;
          play(teams[i], teams[j]);
          cout << "Round " << k << " winner" << endl;
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};

class TableTennis : public Game {
public:
  int numberOfTeams;
  int numberOfRounds;
  Team team;

public:
  TableTennis(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  // in chess there will be only two persons in each team so we need to check
  // the number of members in the team then input the players in the team

  bool checkValidTeams(vector<Team> teams) {
    // Check if there are two or fewer players from each team
    for (Team team : teams) {
      if (team.players.size() < 3 && team.players.size() == 0) {
        return false;
      }
    }
    return true;
  }

  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          cout << "Round  " << k << endl;
          play(teams[i], teams[j]);
          cout << "Round " << k << " winner" << endl;
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};
class Basketball : public Game {
public:
  int numberOfTeams;
  int numberOfRounds; // usually 4 rounds or 4 quarters
  Team team;

public:
  Basketball(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  // in chess there will be only two persons in each team so we need to check
  // the number of members in the team then input the players in the team

  bool checkValidTeams(vector<Team> teams) {
    // Check if there are two or fewer players from each team
    for (Team team : teams) {
      if (team.players.size() != 12) {
        return false;
      }
    }
    return true;
  }

  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          cout << "Round  " << k << endl;
          play(teams[i], teams[j]);
          cout << "Round " << k << " winner" << endl;
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};
class Soccer : public Game {
public:
  int numberOfTeams;
  int numberOfRounds; // usually 4 rounds or 4 quarters
  Team team;

public:
  Soccer(int numberOfTeams, int numberOfRounds)
      : Game(numberOfTeams, numberOfRounds) {
    this->numberOfTeams = numberOfTeams;
    this->numberOfRounds = numberOfRounds;
  }
  void addPlayer(Player player) { this->team.addPlayer(player); }
  void play(Team t1, Team t2) { this->team.play(t1, t2); }
  void declareWinner(Team t1, Team t2) { this->team.declareWinner(t1, t2); }
  // in chess there will be only two persons in each team so we need to check
  // the number of members in the team then input the players in the team

  bool checkValidTeams(vector<Team> teams) {
    // Check if there are two or fewer players from each team
    for (Team team : teams) {
      if (team.players.size() != 11) {
        return false;
      }
    }
    return true;
  }

  void generateMatches(vector<Team> teams) {
    // Generate all possible matches between the teams
    for (int i = 0; i < teams.size(); i++) {
      for (int j = i + 1; j < teams.size(); j++) {
        // Play the match between the two teams
        for (int k = 1; k <= numberOfRounds; k++) {
          cout << "Round  " << k << endl;
          play(teams[i], teams[j]);
          cout << "Round " << k << " winner" << endl;
          declareWinner(teams[i], teams[j]);
        }
        cout << "----------------------------------Next "
                "match----------------------------------------------"
             << endl;
      }
    }
  }
};
class GameFactory {
public:
  static Game *createGame(const string &gameType, int numberOfTeams,
                          int numberOfRounds) {
    if (gameType == "Chess") {
      return new Chess(numberOfTeams, numberOfRounds);
    } else if (gameType == "Cricket") {
      return new Cricket(numberOfTeams, numberOfRounds);
    } else if (gameType == "Wrestling") {
      return new WrestlingGame(numberOfTeams, numberOfRounds);
    } else if (gameType == "Badminton") {
      return new Badminton(numberOfTeams, numberOfRounds);
    } else if (gameType == "TableTennis") {
      return new TableTennis(numberOfTeams, numberOfRounds);
    } else if (gameType == "Basketball") {
      return new Basketball(numberOfTeams, numberOfRounds);
    } else if (gameType == "Soccer") {
      return new Soccer(numberOfTeams, numberOfRounds);
    } else {
      throw invalid_argument("Invalid game type.");
    }
  }
};
int main() {
  cout << "Welcome to the Game Management System!" << endl;
  try {
    int numberOfTeams, numberOfRounds;
    cout << "Enter the number of teams: ";
    cin >> numberOfTeams;
    if (numberOfTeams <= 0) {
      throw invalid_argument("Number of teams must be greater than 0.");
    }

    cout << "Enter the number of rounds: ";
    cin >> numberOfRounds;
    if (numberOfRounds <= 0) {
      throw invalid_argument("Number of rounds must be greater than 0.");
    }

    string gameType;
    cout << "Choose a game: Chess, Cricket, Wrestling, Badminton, Table "
            "Tennis, Basketball, or Soccer: ";
    cin >> gameType;

    Game *game =
        GameFactory::createGame(gameType, numberOfTeams, numberOfRounds);

    vector<Team> teams;
    for (int i = 1; i <= numberOfTeams; i++) {
      Team team;
      cout << "Enter the name of Team " << i << ": ";
      cin >> team.name;
      int numberofPlayers;
      cout << "Enter the number of players in Team " << i << ": ";
            cin >> numberofPlayers;
       if (numberofPlayers <= 0)
      {
         throw InvalidNumberOfPlayers();
      }
      if (gameType == "Chess")
      {
        if(numberofPlayers!=2)
        {throw InvalidNumberOfPlayers();}
        
      } else if (gameType == "Cricket")
      {
        if(numberofPlayers != 11)
        {throw InvalidNumberOfPlayers();}
        
      } else if (gameType == "Wrestling")
      {
        if( numberofPlayers!=1)
        {throw InvalidNumberOfPlayers();}
       
      } else if (gameType == "Badminton")
      {
        if(numberofPlayers>4)
        {throw InvalidNumberOfPlayers();}
      } else if (gameType == "TableTennis")
      {
       if(numberofPlayers>4)
        {throw InvalidNumberOfPlayers();} 
      } 
      else if (gameType == "Basketball")
      {
        if(numberofPlayers!=12)
        {
          throw InvalidNumberOfPlayers();
        }
        
      }
      else if (gameType == "Soccer") 
      {
        if( numberofPlayers!= 11)
        { throw InvalidNumberOfPlayers();}
       
      }

      for (int j = 1; j <= numberofPlayers; j++) {
        string playerName;
        cout << "Enter the name of Player " << j << " in Team " << i << ": ";
        cin >> playerName;
        Player player(playerName);
        team.addPlayer(player);
      }

      teams.push_back(team);
    }

    if (!game->checkValidTeams(teams)) {
      throw invalid_argument("Invalid team configuration.");
    } else {
      game->generateMatches(teams);
    }

    delete game;
  }
    catch (const InvalidNumberOfPlayers& e) 
    {
    cerr << "Error: " << e.what() << endl;
    } 
  catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  } catch (...) {
    cerr << "Unknown error occurred." << endl;
  }
  return 0;
}
