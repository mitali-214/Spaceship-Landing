#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void drawStars() {
    // Draw random twinkling stars in the background
    for (int i = 0; i < 200; i++) {
        int x = rand() % getmaxx();
        int y = rand() % (getmaxy() / 2); // Only in the upper half for stars
        putpixel(x, y, RED); // Draw a star
    }
}

void drawSpaceship(int x, int y, int pulse) {
    // Draw the spaceship
    setcolor(BLUE);
    rectangle(x - 15, y, x + 15, y + 10); // Body
    line(x - 10, y, x, y - 20 + pulse); // Left wing
    line(x + 10, y, x, y - 20 + pulse); // Right wing
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,NULL);

    int spaceshipX = getmaxx() / 2; // Center spaceship horizontally
    int spaceshipY = 50; // Initial vertical position
    int pulse = 0; // Pulse effect for spaceship

    while (spaceshipY < getmaxy() - 50) { // Until it lands
        cleardevice(); // Clear the screen

        // Draw stars
        drawStars();

        // Update spaceship pulse effect
        pulse = (pulse + 1) % 10; // Simple pulse effect

        // Draw spaceship
        drawSpaceship(spaceshipX, spaceshipY, pulse);

        // Move spaceship downwards
        spaceshipY += 2; // Adjust speed here

        delay(50); // Delay for smooth animation
    }

    // Final landing
    cleardevice();
    drawStars();
    drawSpaceship(spaceshipX, getmaxy() - 50, 0); // Draw spaceship on the ground

    delay(3000); // Show landing for a while
    closegraph(); // Close the graphics window
    return 0;
}

