#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

enum Suit {
    clubs, diamonds, hearts, spades
};
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card {
private:
    int number;

    Suit suit;

public:
    void set(int n, Suit s) {
        number = n;
        suit = s;
    }

    void show() const {
        if (number >= 2 && number <= 10) {
            cout << number;
        } else {
            switch (number) {
                case 11:
                    cout << 'J';
                    break;

                case 12:
                    cout << 'Q';
                    break;

                case 13:
                    cout << 'K';
                    break;

                case 14:
                    cout << 'A';
                    break;
            }
        }
        switch (suit) {
            case clubs:
                cout << static_cast<char>(5);
                break;

            case diamonds:
                cout << static_cast<char>(4);
                break;

            case hearts:
                cout << static_cast<char>(3);
                break;

            case spades:
                cout << static_cast<char>(6);
                break;
        }
    };
};

int main() {
    const int TOTAL_CARDS = 52;
    Card deck[TOTAL_CARDS];

    for (int i = 0; i < TOTAL_CARDS; ++i) {
        deck[i].set(i % 13 + 2,
                    Suit(i / 13));
    }

    cout << "\nOrdered deck:" << endl;
    for (int i = 0; i < TOTAL_CARDS; ++i) {
        deck[i].show();
        cout << ' ';
        if (((i + 1) % 13) == 0) {
            cout << endl;
        }
    }

    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; ++i) {
        int randomIndex = rand() % 52;
        swap(deck[i], deck[randomIndex]);
    }

    cout << "\nShuffled deck:" << endl;
    for (int i = 0; i < TOTAL_CARDS; ++i) {
        deck[i].show();
        cout << ' ';
        if (((i + 1) % 13) == 0) {
            cout << endl;
        }
    }

    const int TOTAL_PLAYERS = 4;
    const int TOTAL_CARDS_PER_PLAYER = TOTAL_CARDS / TOTAL_PLAYERS;
    Card players[TOTAL_CARDS][TOTAL_CARDS_PER_PLAYER];

    for (int i = 0; i < TOTAL_CARDS; ++i) {
        players[i % 4][i % 13] = deck[i];
    }

    for (int i = 0; i < TOTAL_PLAYERS; ++i) {
        cout << "\nPlayer No " << i + 1 << ':' << endl;
        for (int j = 0; j < TOTAL_CARDS_PER_PLAYER; ++j) {
            players[i][j].show();
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}