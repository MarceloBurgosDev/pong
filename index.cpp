#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    // Objets
    sf::RenderWindow window(sf::VideoMode({700, 500}), "SFML funciona!");
    
    sf::RectangleShape rectangle(sf::Vector2f(10.f,40.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition({50.f, 250.f});

    sf::RectangleShape rectangleIa(sf::Vector2f(10.f, 40.f));
    rectangleIa.setFillColor(sf::Color::Blue);
    rectangleIa.setPosition({650.f, 250.f});

    sf::CircleShape circle(5.f);
    circle.setFillColor(sf::Color::White);
    circle.setPosition({350.f, 250.f});
   

    // Perimetro
    


    // Text obj
    const sf::Font font("/usr/share/fonts/noto/NotoSans-Black.ttf");
    sf::Text hello(font, "Hello to my video game", 20);
    hello.setPosition({220, 20});
    
    // speed
    float speed {0.1f};
    float circleSpeed {0.05};


    // Game Loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
       
      circle.move({-circleSpeed, 0.f});  
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        rectangle.move({0.f, speed});
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        rectangle.move({0.f, -speed});
      }

      


        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(rectangleIa);
        window.draw(hello);
        window.display();

      // Collision
      sf::FloatRect player = rectangle.getGlobalBounds();
      sf::FloatRect ball = circle.getGlobalBounds();
      sf::FloatRect ia = rectangleIa.getGlobalBounds();

      if (const std::optional<sf::FloatRect> intersection = player.findIntersection(ball)) {
        std::cout << "Hubo choque";
      }

    }

    return 0;
}

