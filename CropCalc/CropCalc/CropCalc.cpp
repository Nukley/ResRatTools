#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//Thanks MusicalProgrammer!

double cutStringUp(int Value1, int Value2, string in)
{
    stringstream RatVal;
    RatVal << in.substr(Value1, Value2);
    double Rat;
    RatVal >> Rat;
    return Rat;
}
int findX(string input) {
    return input.find("x");
}

int main()
{
    int ratioSeperator;
    int splitCropTo;
    string ratioIn;
    string cropTo;
    cout << "This goes good with ResCalc!\n";
    cout << "Insert initial resolution (ex. 1920x1080): ";
    cin >> ratioIn;
    cout << "Insert resolution to crop to (ex. 1280x720): ";
    cin >> cropTo;


    ratioSeperator = findX(ratioIn);
    splitCropTo = findX(cropTo);
    int RatVals[] = { cutStringUp(0, ratioSeperator, ratioIn), cutStringUp(ratioSeperator + 1, -1, ratioIn) };
    int CropVals[] = { cutStringUp(0, splitCropTo, cropTo), cutStringUp(splitCropTo + 1, -1, cropTo) };
    int finalResOne = (RatVals[0] - CropVals[0]) / 2;
    int finalResTwo = (RatVals[1] - CropVals[1]) / 2;

    cout << finalResOne << "x" << finalResTwo;
    cout << "\nYou might have to experiment with the numbers a slight bit!";
    cout << "\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
}