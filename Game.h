#ifndef GAME_H
#define GAME_H

#include <cmath>


class Game {
    private:
        int score_, lives_;
        float time_;
    public:
        Game();
		
        virtual ~Game() = default;
        
        //disabled constructors & operators
		Game(const Game& obj) = delete;	// copy
		Game(Game&& obj) = delete;		// move
		Game& operator = (const Game& obj) = delete;	// copy operator
		Game& operator = (Game&& obj) = delete;		// move operator

        inline float getScore() const
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
        inline float getLives() const
		{
			return lives_;
		}
		
		inline void setLives(int liveAdjustment)
		{
			lives_ = lives_ + liveAdjustment;
		}

		inline void loseLife()
		{
			lives_ = lives_ - 1;
		}

		inline void gainLife()
		{
			lives_ = lives_ + 1;
		}

        inline float getTime() const
		{
			return time_;
		}
		
		inline void setTime(int dt)
		{
			time_ = time_ - dt;
		}

};

#endif  //  GAME_H