    #include <windows.h>
    #include <map>
    #include <iostream>
    using namespace std;


    class CColourSet {
        public:
            // Constructor. The defaultColour is used if value passed to GetColour is less than the lowest cutoffValue.
            CColourSet(COLORREF defaultColour) {
                    m_default_colour = defaultColour;
            }

            // AddCutoff return false if the passed cutoffValue already exists in the
            // ColourSet or true if it was added successfully.
            bool AddCutoff(double cutoffValue, COLORREF colour){
                if (cutoffs.find(cutoffValue) != cutoffs.end()) {
                    return false;
                }

                cutoffs[cutoffValue] = colour;
                return true;
            }

            //The colour returned by GetColour is the colour associated with the
            // largest cutoffValue that is less than or equal to value. If value is less
            // than the lowest cutoffValue then the defaultColour passed to the constructor is returned.
            COLORREF GetColour(double value) const {
                auto it = cutoffs.upper_bound(value);
                if (it == cutoffs.begin()) {
                    return m_default_colour;
                }
                --it;
                return it->second;
            }

        private:
            COLORREF m_default_colour; // default value of color
            map<double, COLORREF> cutoffs; // map to store cutoff values and colors
    };


    // function to show easily values of RGB
    void print_RGB(COLORREF colour) {
        int R = GetRValue(colour);
        int G = GetGValue(colour);
        int B = GetBValue(colour);
        cout << "Color: R=" << R << ", G=" << G << ", B=" << B << endl;
    }

    int main() {
        CColourSet colour_set(RGB(0, 0, 0));// set black(0,0,0) as default color

        colour_set.AddCutoff(10, RGB(255, 0, 0));// we set 10 as cutoff value with color RGB(255, 0, 0)
        colour_set.AddCutoff(50, RGB(0, 255, 0));// we set 50 as cutoff value with color RGB(0, 255, 0)

        //Tests with different values
        COLORREF colour;
        colour = colour_set.GetColour(0);
        print_RGB(colour);
        colour = colour_set.GetColour(9);
        print_RGB(colour);
        colour = colour_set.GetColour(25);
        print_RGB(colour);
        colour = colour_set.GetColour(50);
        print_RGB(colour);

        return 0;
    }
