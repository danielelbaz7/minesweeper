#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create a window with dimensions 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test Window");

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window if the event is "Closed"
            }
        }

        // Clear the window with a white background
        window.clear(sf::Color::White);

        // Create a green circle
        sf::CircleShape circle(50); // Radius of 50 pixels
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(375, 275); // Position the circle in the center

        // Draw the circle
        window.draw(circle);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
