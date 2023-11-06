#ifndef GAME_H
#define GAME_H

#include <cmath>
#include <stdio.h>
#include <iostream>

class Game {
    private:
        int score_, lives_;
        int time_;
		bool gameStatus_;
    public:
        Game();
		
        virtual ~Game() = default;
        
        //disabled constructors & operators
		Game(const Game& obj) = delete;	// copy
		Game(Game&& obj) = delete;		// move
		Game& operator = (const Game& obj) = delete;	// copy operator
		Game& operator = (Game&& obj) = delete;		// move operator


		inline void resetGame()
		{
			//give a flag for running the game and stopping the game when 0 lives. 
			gameStatus_ = true;
			score_ = 0;
    		lives_ = 3;
    		time_ = 10000;
		}

		inline bool getGameStatus() const
		{
			//give a flag for running the game and stopping the game when 0 lives. 
			return gameStatus_;
		}

		inline void stopGame()
		{
			//give a flag for running the game and stopping the game when 0 lives. 
			gameStatus_ = false;
		}


        inline int getScore() const
		{
			return score_;
		}
		
		inline void increaseScore(int points)
		{
			score_ = score_ + points;
            if(score_ % 10000 == 0){
                setLives(1);
            }
		}
        inline int getLives() const
		{
			return lives_;
		}
		
		inline void setLives(int liveAdjustment)
		{
			lives_ = lives_ + liveAdjustment;
			if(lives_ == 0){
				// std::cout << "game over" << std::endl;
				stopGame();
			}
				
		}

		inline void loseLife()
		{
			lives_ = lives_ - 1;
			if(lives_ == 0){
				// std::cout << "game over" << std::endl;
				stopGame();
			}
		}

		inline void gainLife()
		{
			lives_ = lives_ + 1;
		}

        inline int getTime() const
		{
			return time_;
		}
		
		inline void setTime(int dt)
		{
			std::cout << "decrease time" << time_  << " | " << dt << std::endl;
			time_ = time_ - dt;
		}

};

#endif  //  GAME_H