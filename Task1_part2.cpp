#include <string>
#include <map>
#include <windows.h>
#include <iostream>
using namespace std;

class CTextColourSet {
    public:
        // Constructor. The defaultColour is used if no matching label is found.
        CTextColourSet(COLORREF defaultColour) {
            m_default_colour = defaultColour;
        }

        // Method adds an item to the colour set lookup table to specify a colour for the text label
        bool AddLabel(const string& label, COLORREF colour) {
            if (labels.find(label) != labels.end()) {
                return false; // if it is already exists
            }
            labels[label] = colour;
            return true;
        }

        // Method matches a given text label to a colour, if no then return default colour
        COLORREF GetColour(const string& label) const {
            auto it = labels.find(label);
            if (it == labels.end()) {
                return m_default_colour;
            }
            return it->second;
        }

    private:
        COLORREF m_default_colour; // default color
        map<string, COLORREF> labels; // // map to store label names and colors
};

// function to show easily values of RGB
void print_RGB(COLORREF colour) {
    int R = GetRValue(colour);
    int G = GetGValue(colour);
    int B = GetBValue(colour);
    cout << "Color: R=" << R << ", G=" << G << ", B=" << B << endl;
}

int main() {
    CTextColourSet colour_set(RGB(0, 0, 0));// set black(0,0,0) as default color

    colour_set.AddLabel("gold", RGB(255, 215, 0)); // set 'gold' with color of gold
    colour_set.AddLabel("iron", RGB(161, 157, 148));// set 'iron' with color of iron
    colour_set.AddLabel("bronze", RGB(205, 127, 50)); // set 'bronze' with color of brone


    COLORREF colour;
    colour = colour_set.GetColour("stone");
    print_RGB(colour);

    colour = colour_set.GetColour("gold");
    print_RGB(colour);

    colour = colour_set.GetColour("bronze");
    print_RGB(colour);

    colour = colour_set.GetColour("iron");
    print_RGB(colour);

    return 0;
}
