#include <include/SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(sf::VideoMode(600, 600), "main");
    window.setFramerateLimit(20);
    int angle = 90;
    float x = 1, y = 0;
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
            else if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::W){
                    angle += 5;
                }
                else if(event.key.code == Keyboard::S){
                    angle -= 5;
                }

                if(angle > 360){
                    angle -= 360;
                }
                if(angle < 0){
                    angle += 360;
                }

                if(angle >= 45 && angle <= 135){
                    y = -1 + 1/45.0*(angle-45);
                }
                else if(angle >= 225 && angle <= 315){
                    y = 1 - 1/45.0*(angle-225);
                }
                
                if(angle >= 135 && angle <= 225){
                    x = 1 - 1/45.0 * (angle-135);
                }
                else if(angle >= 315){
                    x = -1 + 1/45.0 * (angle-315);
                }
                else if(angle <= 45){
                    x = 1/45.0 * angle;
                }
                

                if(angle == 360){
                    angle = 0;
                }

                cout << angle << ' ' << x << ' ' << y << '\n';
                window.clear(Color::Black);
                for(int i = 0; i < 100; i++){
                    RectangleShape rect(Vector2f(1, 1));
                    rect.setPosition(int(300 + i * x), int(300 + i * y));
                    rect.setFillColor(Color::White);
                    window.draw(rect);
                }
                window.display();
            }
        }
    }
}