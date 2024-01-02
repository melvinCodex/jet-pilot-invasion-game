#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <windows.h>


class objectss
    {
        std::vector<sf::CircleShape> balls;
        sf::CircleShape ball;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f pos;
        sf::FloatRect ballBounds;
        float initxpos[10];
        float radius = 30;
        float maxTimer = 25.f;
        float timer = 0.f;
        int maxBalls = 1000000;
        float red ;
        float blue ;
        float green ;

        public:

        objects(){}

        void initTexture(){
            texture.loadFromFile("pics/mars.JPEG", sf::IntRect(10,100,800,600));
            //texture.isSmooth(true);

            sprite.setTexture(texture);
            sprite.setColor(sf::Color(225, 170, 75, 255));
            sprite.setScale(1.f,1.f);
        }
        void initBall(){
           // ball.setPosition(pos);
            ball.setRadius(radius);
            ball.setPointCount(70);
            ball.setOutlineColor(sf::Color::Black);
            ball.setOutlineThickness(5.f);
            ballBounds = ball.getGlobalBounds();

        }
        void Spawnobj(){
            pos.x = static_cast<float>((rand( )*777)%770);
            pos.y = 0.f;
            red = rand()%255;
            blue = rand()%255;
            green = rand()%255;
            ball.setFillColor(sf::Color(red,blue,green,185));
            ball.setPosition(pos);
            balls.push_back(ball);
        }
        void updateTimer(){
            if(balls.size()<maxBalls){
                if(timer >= maxTimer){
                    Spawnobj();
                    timer = 0.f;

                }

                else{
                    timer += 1.f;
                }
            }
        }
        void movement(sf::RenderWindow& wind){
        for( auto& ball : balls){
           ball.move(0.f,3.f);
           //pos.y += 3.f;
            }

            }
        void render(sf::RenderWindow& wind){
        for( auto& ball : balls){
                wind.draw(ball);
            }
            }
        void renderr(sf::RenderWindow& wind){
            //std::cout<<"this stuff works";
              wind.draw(sprite);
            }
        void setFillcolour(){
            ball.setFillColor(sf::Color(0,0,0,0));
        }
        float getRadius(){
            return radius;
        }
        sf::Vector2f getPosition(){
            return pos;
        }
        sf::FloatRect getBallbounds(){
            return ballBounds;
        }


    };
class jet
    {
        sf::Vector2f jpos;
        sf::Texture bomber;
        sf::Sprite bsprite;
        float yposmax;

        public:
        jet(float pos_x,float pos_y,float yposmax){
            jpos.x = pos_x;
            jpos.y = pos_y;
            this->yposmax = yposmax;
        }
        void jinit(){
            bomber.loadFromFile("pics/jet.JPG", sf::IntRect(0,0,600,800));
            bsprite.setTexture(bomber);
            bsprite.setColor(sf::Color(90,50,200,215));
            bsprite.setOrigin(12,5);
            //bsprite.rotate(90);
            float px = 0.15;
            float py = 0.15;
            bsprite.setScale(px,py);
            //bomber.isSmooth(true);
            bsprite.setPosition(jpos);
            sf::FloatRect bombBounds = bsprite.getGlobalBounds();
        }
        void jmovement(){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    jpos.x = jpos.x - 10;
                    if(jpos.x<=0){
                    jpos.x = 0;
                    }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    jpos.x = jpos.x + 10;
                    if(jpos.x>=780){
                    jpos.x = 780;
                    }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    jpos.y = jpos.y - 7;
                    if(jpos.y<=yposmax){
                    jpos.y = yposmax;
                    }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                     jpos.y = jpos.y + 7;
                    if(jpos.y>=520){
                    jpos.y =520 ;
                    }
            }
        }

        void jrender(sf::RenderWindow& wind){
            wind.draw(bsprite);
        }
        sf::Vector2f get_pos(){
            return jpos;
        }
};
class missile
    {
        std::vector<sf::Sprite> misles;
        sf::Texture bullet;
        sf::Sprite misle;
        sf::Vector2f mpos;
        sf::FloatRect mislBounds;
        float maxTimer = 100.f;
        float timer = 0.f;
        float xp;
        float yp;
        int maxMisls = 500;

        public:

        missile(float pos_x,float pos_y){
           // mpos.x = (rand()*79)%750;
            //mpos.y = pos_y;
        }
        void initmisl(){
            bullet.loadFromFile("pics/bullet.JPG" , sf::IntRect(0,0,200,400));
            misle.setTexture(bullet);
            misle.setColor(sf::Color(120,50,80,180));
            float sx = 0.1;
            float sy = 0.1;
            misle.setScale(sx,sy);
            mislBounds = misle.getGlobalBounds();
        }
        void movement(){
            for(auto& misle : misles){
             misle.move(0.f,-35.f);
            }

        }
        void gameLogic(objectss& ball,jet& bombBounds){

           //  for(auto& ball : balls){
                for(auto& misle : misles){
                /*if(((ball.getPosition().y + (2*ball.getRadius())+5) == mpos.y ) &&
                    ((mpos.x > ball.getPosition().x - 50) && ((ball.getPosition().x +(2*ball.getRadius()) + 10) > mpos.x)  )){
                    ball.setFillcolour();
                }*/

//                 if(mislBounds.intersects(ball.getBounds)){
                 ball.setFillcolour();
            }
            }

          //  if(ballBounds.intersects(bombBounds)){
            //   ball.setFillcolour();
            //}
       // }
        void retrieve(jet& bsprite){
            xp = bsprite.get_pos().x + 40;
            yp = bsprite.get_pos().y - 35;
            //std::cout<<"this b works";
        }
        void spawnmisl(){
            mpos.x = xp;
            mpos.y = yp;
            misle.setPosition(mpos);
            misles.push_back(misle);
           // std::cout<<"this b works";
        }
        void timerUpdate(){
          if(misles.size()<maxMisls){
            if(timer = maxTimer){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
                       spawnmisl();
                       timer = 0.f;
            }
             else{
                    timer++;
                }
            }
          }
        }
        void mrender(sf::RenderWindow& wind){
                for(auto& misle : misles){
                wind.draw(misle);
            }
        }
};
int main(){
    std::srand(static_cast<unsigned>(time(NULL)));
    objectss stuff;
    jet jetin(390,500,200);
    missile bulin(100,600);
    sf::RenderWindow window(sf::VideoMode(800,600), "praco" ,  sf::Style::Titlebar | sf::Style::Close );
    window.setFramerateLimit(971);
        while (window.isOpen())
                {
                sf::Event event;
                while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed){
                            window.close();
                        }
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                            window.close();
                        }
                    }


       // window.clear();
        //draw calls

        stuff.initTexture();
        stuff.initBall();
        stuff.updateTimer();
        stuff.movement(window);
        stuff.getBallbounds();
        stuff.setFillcolour();

        jetin.jinit();
        jetin.jmovement();

        bulin.initmisl();
        bulin.retrieve(jetin);
        bulin.movement();
        bulin.timerUpdate();
        bulin.gameLogic(stuff,jetin);

        stuff.renderr(window);
        bulin.mrender(window);
        stuff.render(window);
        jetin.jrender(window);

        window.display();
    }

    return 0;
}

