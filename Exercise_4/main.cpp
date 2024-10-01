#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum SUIT
{
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS,
    JOKER,
};

enum Value
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
};

struct Card
{
    union
    {
        Value numberValue;
        char charValue;
    };
    SUIT suit;
};

void makeDeckOfCard(Card* deck, int deckSize)
{
    int index = 0;
    for (int i = SPADES; i <= DIAMONDS; i++)
    {
        for (int j = ACE; j <= KING; j++)
        {

            deck[index].suit = static_cast<SUIT>(i);

            if (j >= TWO && j <= TEN)
            {
                deck[index].numberValue = static_cast<Value>(j);
            }
            else
            {
                switch (j)
                {
                case ACE:
                    deck[index].charValue = 'A';
                    break;
                case JACK:
                    deck[index].charValue = 'J';
                    break;
                case QUEEN:
                    deck[index].charValue = 'Q';
                    break;
                case KING:
                    deck[index].charValue = 'K';
                    break;
                default:
                    break;
                }
            }
            index++;
        }
    }
    deck[index].suit = JOKER;
    index++;
    deck[index].suit = JOKER;
}

void displayDeck(Card deck[], int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        if (deck[i].suit == JOKER)
        {
            cout << "Joker" << endl;
        }
        else if (deck[i].numberValue >= TWO && deck[i].numberValue <= TEN)
        {
            cout << deck[i].numberValue << " of ";
        }
        else
        {
            cout << deck[i].charValue << " of ";
        }
        switch (deck[i].suit)
        {
        case SPADES:
            cout << "Spades" << endl;
            break;
        case HEARTS:
            cout << "Hearts" << endl;
            break;
        case CLUBS:
            cout << "Clubs" << endl;
            break;
        case DIAMONDS:
            cout << "Diamonds" << endl;
            break;
        default:
            break;
        }

    }
}
void shuffleDeck(Card* deck, int deckSize ) {
    srand(time(NULL));
    for (int i = deckSize - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
    }
}

int main()
{
    const int deckSize = 54;
    Card deck[deckSize];

    makeDeckOfCard(deck, deckSize);

    cout<<"Cards shuffled:"<<endl;
    cout<<endl;
    shuffleDeck(deck, deckSize );
    displayDeck(deck, deckSize);
    return 0;
}
