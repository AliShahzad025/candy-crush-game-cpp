#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<SFML/Audio.hpp>
#include<windows.h>

using namespace std;
using namespace sf;

int score = 0;

Text scoreText;

Texture candyTexture1, candyTexture2, candyTexture3, candyTexture4, candyTexture5;
void swapcandy(vector<vector<Sprite>>& grid, int i, int j, int i1, int j1) {
    swap(grid[i][j], grid[i1][j1]);
}

void swapsprite(Sprite& firstcandy, Sprite& secondcandy) {
    float tempX = firstcandy.getPosition().x;
    float tempY = firstcandy.getPosition().y;
    firstcandy.setPosition(secondcandy.getPosition().x, secondcandy.getPosition().y);
    secondcandy.setPosition(tempX, tempY);
}

void fivehor(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score)
{
    // 5 Horizontal check
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns - 4; ++j) {
            if (candiesMatrix[j][i].getTexture() == candiesMatrix[j + 1][i].getTexture() &&
                candiesMatrix[j][i].getTexture() == candiesMatrix[j + 2][i].getTexture() &&
                candiesMatrix[j][i].getTexture() == candiesMatrix[j + 3][i].getTexture() &&
                candiesMatrix[j][i].getTexture() == candiesMatrix[j + 4][i].getTexture()
                ) {
                score = score + 20;
                // Shift candies down

                for (int q = i; q > 0; --q) {
                    for (int p = 0; p < columns; ++p) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }  for (int l = 0; l < columns; l++) {

                        int randomCandy = rand() % 5;
                        switch (randomCandy) {
                        case 0:
                            candiesMatrix[l][0].setTexture(candyTexture1);
                            break;
                        case 1:
                            candiesMatrix[l][0].setTexture(candyTexture2);
                            break;
                        case 2:
                            candiesMatrix[l][0].setTexture(candyTexture3);
                            break;
                        case 3:
                            candiesMatrix[l][0].setTexture(candyTexture4);
                            break;
                        case 4:
                            candiesMatrix[l][0].setTexture(candyTexture5);
                            break;
                        }
                    }
                }

            }



        }
    }


}
void fivevert(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows - 4; ++j) {
            if (candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 1].getTexture() &&
                candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 2].getTexture() &&
                candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 3].getTexture() &&
                candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 4].getTexture())

            {
                score = score + 20;
                for (int l = 0; l < rows; l++) {
                    Sprite candy;
                    int randomCandy = rand() % 5;
                    switch (randomCandy) {
                    case 0:
                        candiesMatrix[i][l].setTexture(candyTexture1);

                        break;
                    case 1:
                        candiesMatrix[i][l].setTexture(candyTexture2);
                        break;
                    case 2:
                        candiesMatrix[i][l].setTexture(candyTexture3);
                        break;
                    case 3:
                        candiesMatrix[i][l].setTexture(candyTexture4);
                        break;
                    case 4:
                        candiesMatrix[i][l].setTexture(candyTexture5);
                        break;
                    }
                }

            }
        }
    }
}

void fourhor(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score)
{
    // 4 Horizontal check
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns - 3; ++j) {
            if (candiesMatrix[j][i].getTexture() == candiesMatrix[j + 1][i].getTexture() &&
                candiesMatrix[j][i].getTexture() == candiesMatrix[j + 2][i].getTexture() &&
                candiesMatrix[j][i].getTexture() == candiesMatrix[j + 3][i].getTexture()
                ) {
                score = score + 15;
                for (int p = j; p <= j + 3; p++) {
                    for (int q = i; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }  for (int l = j; l <= j + 3; l++) {

                        int randomCandy = rand() % 5;
                        switch (randomCandy) {
                        case 0:
                            candiesMatrix[l][0].setTexture(candyTexture1);
                            break;
                        case 1:
                            candiesMatrix[l][0].setTexture(candyTexture2);
                            break;
                        case 2:
                            candiesMatrix[l][0].setTexture(candyTexture3);
                            break;
                        case 3:
                            candiesMatrix[l][0].setTexture(candyTexture4);
                            break;
                        case 4:
                            candiesMatrix[l][0].setTexture(candyTexture5);
                            break;
                        }
                    }
                }

            }

        }

    }

}




void fourvert(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows - 3; ++j) {
            if (candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 1].getTexture() &&
                candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 2].getTexture() &&
                candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 3].getTexture())

            {
                score = score + 15;
                for (int k = 0; k < j; k++) {


                    candiesMatrix[i][k + 4].setTexture(*candiesMatrix[i][k].getTexture());


                }
                for (int l = 0; l < 4; l++) {
                    Sprite candy;
                    int randomCandy = rand() % 5;
                    switch (randomCandy) {
                    case 0:
                        candiesMatrix[i][l].setTexture(candyTexture1);

                        break;
                    case 1:
                        candiesMatrix[i][l].setTexture(candyTexture2);
                        break;
                    case 2:
                        candiesMatrix[i][l].setTexture(candyTexture3);
                        break;
                    case 3:
                        candiesMatrix[i][l].setTexture(candyTexture4);
                        break;
                    case 4:
                        candiesMatrix[i][l].setTexture(candyTexture5);
                        break;
                    }
                }

            }
        }
    }
}

void vertical(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score)
{
    // for vertical check 3 candies in row 
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows - 2; ++j) {
            if (candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 1].getTexture() &&
                candiesMatrix[i][j].getTexture() == candiesMatrix[i][j + 2].getTexture())
            {
                score = score + 5;
                for (int k = 0; k < j; k++) {


                    candiesMatrix[i][k + 3].setTexture(*candiesMatrix[i][k].getTexture());


                }
                /* Generate new random candies in the top row
               Generate new random candies in the top row*/
                for (int l = 0; l < 3; l++) {
                    Sprite candy;
                    int randomCandy = rand() % 5;
                    switch (randomCandy) {
                    case 0:
                        candiesMatrix[i][l].setTexture(candyTexture1);

                        break;
                    case 1:
                        candiesMatrix[i][l].setTexture(candyTexture2);
                        break;
                    case 2:
                        candiesMatrix[i][l].setTexture(candyTexture3);
                        break;
                    case 3:
                        candiesMatrix[i][l].setTexture(candyTexture4);
                        break;
                    case 4:
                        candiesMatrix[i][l].setTexture(candyTexture5);
                        break;
                    }
                }

            }
        }
    }


}
void horizontal(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score) {


    // Horizontal check
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns - 2; ++j) {
            if (candiesMatrix[j][i].getTexture() == candiesMatrix[j + 1][i].getTexture() &&
                candiesMatrix[j][i].getTexture() == candiesMatrix[j + 2][i].getTexture()) {
                // Shift candies down
                score = score + 5;
                for (int p = j; p <= j + 2; p++) {
                    for (int q = i; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }  for (int l = j; l <= j + 2; l++) {

                        int randomCandy = rand() % 5;
                        switch (randomCandy) {
                        case 0:
                            candiesMatrix[l][0].setTexture(candyTexture1);
                            break;
                        case 1:
                            candiesMatrix[l][0].setTexture(candyTexture2);
                            break;
                        case 2:
                            candiesMatrix[l][0].setTexture(candyTexture3);
                            break;
                        case 3:
                            candiesMatrix[l][0].setTexture(candyTexture4);
                            break;
                        case 4:
                            candiesMatrix[l][0].setTexture(candyTexture5);
                            break;
                        }
                    }
                }

            }



        }
    }

}

// right to left
void rtolcheckdiagonal(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score) {
    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < columns - 2; j++) {
            if (candiesMatrix[j][i].getTexture() == candiesMatrix[j + 1][i + 1].getTexture()
                && candiesMatrix[j][i].getTexture() == candiesMatrix[j + 2][i + 2].getTexture()) {
                score = score + 5;
                for (int p = j; p < j + 1; p++) {
                    for (int q = i; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }
                }

                for (int p = j + 1; p < j + 2; p++) {
                    for (int q = i + 1; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }
                }

                for (int p = j + 2; p < j + 3; p++) {
                    for (int q = i + 2; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }
                }

                for (int l = j; l <= j + 2; l++) {
                    int randomCandy = rand() % 5;
                    switch (randomCandy) {
                    case 0:
                        candiesMatrix[l][0].setTexture(candyTexture1);
                        break;
                    case 1:
                        candiesMatrix[l][0].setTexture(candyTexture2);
                        break;
                    case 2:
                        candiesMatrix[l][0].setTexture(candyTexture3);
                        break;
                    case 3:
                        candiesMatrix[l][0].setTexture(candyTexture4);
                        break;
                    case 4:
                        candiesMatrix[l][0].setTexture(candyTexture5);
                        break;
                    }
                }
            }
        }
    }
}

// left to right
void ltorcheckdiagonal(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score) {
    for (int i = 0; i < rows - 2; i++) {
        for (int j = 2; j < columns; j++) {
            if (candiesMatrix[j][i].getTexture() == candiesMatrix[j - 1][i + 1].getTexture()
                && candiesMatrix[j][i].getTexture() == candiesMatrix[j - 2][i + 2].getTexture()) {
                score = score + 5;
                for (int p = j; p > j - 1; p--) {
                    for (int q = i; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }
                }

                for (int p = j - 1; p > j - 2; p--) {
                    for (int q = i + 1; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }
                }

                for (int p = j - 2; p > j - 3; p--) {
                    for (int q = i + 2; q > 0; q--) {
                        candiesMatrix[p][q].setTexture(*candiesMatrix[p][q - 1].getTexture());
                    }
                }

                for (int l = j; l >= j - 2; l--) {
                    int randomCandy = rand() % 5;
                    switch (randomCandy) {
                    case 0:
                        candiesMatrix[l][0].setTexture(candyTexture1);
                        break;
                    case 1:
                        candiesMatrix[l][0].setTexture(candyTexture2);
                        break;
                    case 2:
                        candiesMatrix[l][0].setTexture(candyTexture3);
                        break;
                    case 3:
                        candiesMatrix[l][0].setTexture(candyTexture4);
                        break;
                    case 4:
                        candiesMatrix[l][0].setTexture(candyTexture5);
                        break;
                    }
                }
            }
        }
    }
}

void  checkMatches(RenderWindow& window, vector<vector<Sprite>>& candiesMatrix, int rows, int columns, int& score) {

    fivehor(window, candiesMatrix, rows, columns, score);
    fivevert(window, candiesMatrix, rows, columns, score);
    fourhor(window, candiesMatrix, rows, columns, score);
    fourvert(window, candiesMatrix, rows, columns, score);
    horizontal(window, candiesMatrix, rows, columns, score);
    vertical(window, candiesMatrix, rows, columns, score);
    rtolcheckdiagonal(window, candiesMatrix, rows, columns, score);
    ltorcheckdiagonal(window, candiesMatrix, rows, columns, score);

}
int moveCounter = 15;
int main() {

    float moveTimeLimit = 20.0f;
    float elapsedTimePerMove = 0.0f;
    Clock clock;
    int rows, columns;
    cout << "ENTER THE NUMBER OF ROWS:";
    cin >> rows;
    cout << "ENTER THE NUMBER OF COLUMNS:";
    cin >> columns;
    cout << "\n";
    float delayTime = 2.0;
    float elapsedTime = 0.0f;
    Music music;
    if (!music.openFromFile("music.ogg")) {
        std::cout << "Error: Failed to load music.ogg" << std::endl;
        return 1;
    }
    music.play();

    RenderWindow window(VideoMode(columns * 150, rows * 150), "Candies Board");
    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Failed to load " << endl;
        return EXIT_FAILURE;
    }
    Texture texture2;
    if (!texture2.loadFromFile("player2.png")) {
        cout << "Failed to load background2.jpg" << endl;
        return 1;
    }

    Sprite sprite(texture2);

    Text moveText;
    moveText.setFont(font);
    moveText.setCharacterSize(30);
    moveText.setFillColor(Color::Black);
    moveText.setString("Move Text");

    Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(30);
    timerText.setFillColor(Color::Black);
    timerText.setString("Timer Text");

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::Black);
    scoreText.setString("Score Text");


    Vector2u windowSize = window.getSize();

    // Calculate positions for each text element at the top right
    float textPadding = 80.0f;
    float offsetY = 50.0f;

    float moveTextX = windowSize.x - moveText.getLocalBounds().width - textPadding;
    moveText.setPosition(moveTextX, 0 + offsetY);

    float timerTextX = windowSize.x - timerText.getLocalBounds().width - textPadding;
    timerText.setPosition(timerTextX, 0 + offsetY * 2);

    float scoreTextX = windowSize.x - scoreText.getLocalBounds().width - textPadding;
    scoreText.setPosition(scoreTextX, 0 + offsetY * 3);

    if (!candyTexture1.loadFromFile("candy1.png")) {
        cout << "Failed to load image: candy1.png" << endl;
        return EXIT_FAILURE;
    }
    if (!candyTexture2.loadFromFile("candy2.png")) {
        cout << "Failed to load image: candy2.png" << endl;
        return EXIT_FAILURE;
    }
    if (!candyTexture3.loadFromFile("candy3.png")) {
        cout << "Failed to load image: candy3.png" << endl;
        return EXIT_FAILURE;
    }
    if (!candyTexture4.loadFromFile("candy4.png")) {
        cout << "Failed to load image: candy4.png" << endl;
        return EXIT_FAILURE;
    }
    if (!candyTexture5.loadFromFile("candy5.png")) {
        cout << "Failed to load image: candy5.png" << endl;
        return EXIT_FAILURE;
    }



    float scale = 50.0f / max(candyTexture1.getSize().x, max(candyTexture2.getSize().x,
        max(candyTexture3.getSize().x, candyTexture4.getSize().x)));

    vector<vector<Sprite>> candiesMatrix(rows, vector<Sprite>(columns));

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            Sprite candy;

            int randomCandy = rand() % 5;


            switch (randomCandy) {
            case 0:
                candy.setTexture(candyTexture1);
                break;
            case 1:
                candy.setTexture(candyTexture2);
                break;
            case 2:
                candy.setTexture(candyTexture3);
                break;
            case 3:
                candy.setTexture(candyTexture4);
                break;
            case 4:
                candy.setTexture(candyTexture5);
                break;
            }
            candy.setScale(scale, scale);
            candy.setPosition(i * 60 + 10, j * 60 + 10);
            candiesMatrix[i][j] = candy;
        }
    }

    int selectedCandyX = 0, selectedCandyY = 0;
    RectangleShape selectionHighlight(Vector2f(50.0f, 50.0f));
    selectionHighlight.setFillColor(Color::Transparent);
    selectionHighlight.setOutlineThickness(2.f);
    selectionHighlight.setOutlineColor(Color::White);
    selectionHighlight.setPosition(selectedCandyY * 60 + 10, selectedCandyX * 60 + 10);

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        elapsedTime += deltaTime;

        elapsedTimePerMove += deltaTime;


        bool verticalcheck = false;
        bool horizontalcheck = false;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::A && selectedCandyY > 0) {
                    if (moveCounter > 0) {

                        swapsprite(candiesMatrix[selectedCandyY][selectedCandyX], candiesMatrix[selectedCandyY - 1][selectedCandyX]);
                        swapcandy(candiesMatrix, selectedCandyY, selectedCandyX, selectedCandyY - 1, selectedCandyX);

                        checkMatches(window, candiesMatrix, rows, columns, score);
                        elapsedTimePerMove = 0.0f;

                        moveCounter--;

                    }
                }
                else if (event.key.code == Keyboard::D && selectedCandyY < rows - 1) {
                    if (moveCounter > 0) {
                        swapsprite(candiesMatrix[selectedCandyY][selectedCandyX], candiesMatrix[selectedCandyY + 1][selectedCandyX]);
                        swapcandy(candiesMatrix, selectedCandyY, selectedCandyX, selectedCandyY + 1, selectedCandyX);
                        checkMatches(window, candiesMatrix, rows, columns, score);
                        elapsedTimePerMove = 0.0f;
                        moveCounter--;

                    }
                }
                else if (event.key.code == Keyboard::W && selectedCandyX > 0) {
                    if (moveCounter > 0) {
                        swapsprite(candiesMatrix[selectedCandyY][selectedCandyX], candiesMatrix[selectedCandyY][selectedCandyX - 1]);
                        swapcandy(candiesMatrix, selectedCandyY, selectedCandyX, selectedCandyY, selectedCandyX - 1);
                        checkMatches(window, candiesMatrix, rows, columns, score);
                        elapsedTimePerMove = 0.0f;

                        moveCounter--;

                    }
                }
                else if (event.key.code == Keyboard::S && selectedCandyX < columns - 1) {
                    if (moveCounter > 0) {
                        swapsprite(candiesMatrix[selectedCandyY][selectedCandyX], candiesMatrix[selectedCandyY][selectedCandyX + 1]);
                        swapcandy(candiesMatrix, selectedCandyY, selectedCandyX, selectedCandyY, selectedCandyX + 1);
                        checkMatches(window, candiesMatrix, rows, columns, score);
                        elapsedTimePerMove = 0.0f;

                        moveCounter--;

                    }
                }

            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2i pos = Mouse::getPosition(window);
                    /* y is rows
                    x column*/
                    selectedCandyY = pos.x / 60;
                    selectedCandyX = pos.y / 60;

                }

            }


        }
        float remainingTime = moveTimeLimit - elapsedTimePerMove;
        if (remainingTime < 0) {
            remainingTime = 0;
        }
        selectionHighlight.setPosition(selectedCandyY * 60 + 10, selectedCandyX * 60 + 10);

        window.clear();
        window.draw(sprite);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                window.draw(candiesMatrix[i][j]);

            }
        }
        if (elapsedTime >= delayTime) {

            checkMatches(window, candiesMatrix, rows, columns, score);

            elapsedTime = 0.0f;
        }
        moveText.setString("Moves left: " + to_string(moveCounter));

        window.draw(moveText);
        timerText.setString("Time: " + to_string(static_cast<int>(remainingTime)));

        scoreText.setString("Score: " + std::to_string(score));

        window.draw(selectionHighlight);
        window.draw(timerText);
        window.draw(scoreText);
        window.display();
    }
    return 0;
}