#include "pong.hpp"

int main(){

  /*Creation of game elements*/

  //non-static game elements
	 // Create the main window
    sf::RenderWindow window(sf::VideoMode(X_RES, Y_RES), "Super Pong");
    //I dont want to rewrite the background
    Player player1(sf::Vector2f(X_RES/6,Y_RES/2), sf::Vector2f(X_RES/50, Y_RES/5), sf::Color(3,0,163,255), false);
    Player player2(sf::Vector2f(5*X_RES/6,Y_RES/2), sf::Vector2f(X_RES/50, Y_RES/5), sf::Color(163,3,0,255), true);
    Ball pong(10, sf::Vector2f(1, 1), sf::Vector2f(X_RES/2, Y_RES/2),  sf::Color(0,0,0,255));
    //static game elements



    //used by the fps counter, these could be globalized but its not nessary
    time_t last = time(NULL);
    int counter; //this holds the acutal counted FPS value thats displayed once per second
    sf::Clock clock;
    clock.restart();
    sf::Time gameTime;
    while (window.isOpen())
    {
        window.clear(sf::Color(255,255,255,255));
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
              case sf::Event::Closed:
                window.close();
                break;
              /*case sf::Event::KeyPressed:
              /  switch(event.key.code){
                  case sf::Keyboard::S:
                    //std::cout << "Pressed S\n";
                    float x = (player1.GetPos().x);
                    float y =  (player1.GetPos().y);
                    player1.UpdatePos(x, ++y);
                    break;
                }*/
            }

        }
        gameTime = clock.getElapsedTime();
        pong.checkBounce(player1.GetPos(), player2.GetPos(), sf::Vector2f(X_RES/50, Y_RES/5)); //thrid arugment is the size of the paddle
        if(gameTime.asMicroseconds() > 1000){ // checks every 100 milliseconds
          clock.restart();
          pong.updatePos(pong.GetPos().x+pong.getVel().x, pong.GetPos().y+pong.getVel().y);
        }
        // Clear screen
        // Draw the Player

        player1.UpdatePos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        player2.UpdatePos(player2.GetPos().x, pong.GetPos().y);
        player1.Draw(window);
        player2.Draw(window);
        pong.draw(window);
        fps_counter(window, &last, &counter);
        // Update the window
        window.display();

    }
    return EXIT_SUCCESS;

}

/*
Works by counting up the counter and waiting for ten seconds to pass since the last Update
it then displays the average value to the console
you can make it display ingame but I was running into the problem of
it not displaying all the time, it flickers, console output is much easier
*/
void fps_counter(sf::RenderWindow &window, time_t *last, int *count){

  time_t current = time(NULL);
  if(difftime(current, *last) == 10){
    last[0] = current;
    /*
    sf::Font font;
    // Load it from a file
    if (!font.loadFromFile("resources/blazed.ttf"))
    {
    }
    sf::Text text1;
    text1.setFont(font);
    text1.setCharacterSize(30);
    text1.setStyle(sf::Text::Regular);
    text1.setString(std::to_string(count[0]));
    window->draw(text1);
    */
    std::cout << "Average FPS: " << count[0]/10 << std::endl;
      count[0] = 0;
  }
  count[0]++;
}
