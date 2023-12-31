#include <iostream>

using namespace std;
typedef double (*conv) (double s, int a);

namespace Temperature {
  const double kelvinToCelsius = 273.15;
  const double celsiusToFahrenheitCoeff = 1.8;
  const double celsiusToFahrenheit = 32.0;
  const double celsiusMin = -273.15;
  const double fahrenheitMin = -459.67;
  const double kelvinMin = 0.0;
};

namespace Speed {
  const double kphToMphCoeff = 0.621371;
};

namespace Length {
  const double kilometerToLightyearCoeff = 1.057e-13;
  const double meterToFeetCoeff = 3.28084;
  const double centimeterToInchCoeff = 0.393701;
};

namespace Weight {
  const double kilogramToPoundCoeff = 2.205;
};

namespace Fuel {
  const double litersToMilesPerGallonCoeff = 235.215;
};

int getChoiceOfConv() {
  int choiceConv = 0;
  
  cout << "Welcome to Unit converter. Please enter one of the following options:" << endl;
  cout << "1. Temperature" << endl;
  cout << "2. Speed" << endl;
  cout << "3. Length" << endl;
  cout << "4. Weight" << endl;
  cout << "5. Fuel economy" << endl;

  std::cout << "Your choice: ";
  std::cin >> choiceConv;
  return choiceConv;
}

double tempConv(double start, int conv)
{
  switch (conv) {
    case 1:
      // c - f
      if(start < Temperature::celsiusMin)
      {
        cout << "Value out of bounds!" << endl;
        exit(1);
      }
      return start * Temperature::celsiusToFahrenheitCoeff + Temperature::celsiusToFahrenheit;
    case 2:
      if(start < Temperature::fahrenheitMin)
      {
        cout << "Value out of bounds!" << endl;
        exit(1);
      }
      return (start- Temperature::celsiusToFahrenheit) / Temperature::celsiusToFahrenheitCoeff;
    case 3:
      //c - k
      if(start < Temperature::celsiusMin)
      {
        cout << "Value out of bounds!" << endl;
        exit(1);
      }
      return start+ Temperature::kelvinToCelsius;
    case 4:
      if(start < Temperature::kelvinMin)
      {
        cout << "Value out of bounds!" << endl;
        exit(1);
      }
      return start- Temperature::kelvinToCelsius;
    case 5:
      //f - k
      if(start < Temperature::fahrenheitMin)
      {
        cout << "Value out of bounds!" << endl;
        exit(1);
      }
      return ((start- Temperature::celsiusToFahrenheit) / Temperature::celsiusToFahrenheitCoeff) + Temperature::kelvinToCelsius;
    case 6:
      if(start < Temperature::kelvinMin)
      {
        cout << "Value out of bounds!" << endl;
        exit(1);
      }
      return (start- Temperature::kelvinToCelsius) * Temperature::celsiusToFahrenheitCoeff + Temperature::celsiusToFahrenheit;
  }
}

double speedConv(double start, int conv)
{
  switch (conv) {
    case 1:
      //kph - mph
      return start * Speed::kphToMphCoeff;
    case 2:
      return start / Speed::kphToMphCoeff;
  }
}

double lengthConv(double start, int conv)
{
  if(start < 0)
  {
    cout << "Invalid value!" << endl;
    exit(1);
  }
  switch (conv) {
    case 1:
      // ly - km
      return start / Length::kilometerToLightyearCoeff;
    case 2:
      return start * Length::kilometerToLightyearCoeff;
    case 3:
      //m - f
      return start * Length::meterToFeetCoeff;
    case 4:
      return start / Length::meterToFeetCoeff;
    case 5:
      //cm - inch
      return start * Length::centimeterToInchCoeff;
    case 6:
      return start / Length::centimeterToInchCoeff;
  }
}

double weightConv(double start, int conv)
{
  if(start < 0)
  {
    cout << "Invalid value!" << endl;
    exit(1);
  }
  switch (conv) {
    case 1:
      //kg - lb
      return start * Weight::kilogramToPoundCoeff;
    case 2:
      return start / Weight::kilogramToPoundCoeff;
  }
}

double fuelConv(double start, int conv)
{
  if(start < 0)
  {
    cout << "Invalid value!" << endl;
    exit(1);
  }
  switch (conv) {
    case 1:
      //l/100km - mpg
      return start * Fuel::litersToMilesPerGallonCoeff;
    case 2:
      return start / Fuel::litersToMilesPerGallonCoeff;
  }
}

void converter(int choiceOfConverter) {
  int choiceOfConversion;
  double start, value = 0;
  const int numOfConvOpts = 5;
  if(choiceOfConverter > numOfConvOpts || choiceOfConverter < 1)
  {
    cout << "Invalid option!" << endl;
    return;
  }
  conv converters[] = {tempConv, speedConv, lengthConv, weightConv, fuelConv};
  const int numOfOpts[numOfConvOpts] = {6, 2, 6, 2, 2};
  string measureName[numOfConvOpts] = {"temperature", "speed", "length", "weight", "fuel economy"};
  //max in numOfOpts = 6
  string opts[numOfConvOpts][6] = {
    {"1. Celsius To Fahrenheit", "2. Fahrenheit To Celsius", "3. Celsius To Kelvin", "4. Kelvin To Celsius", "5. Fahrenheit To Kelvin", "6. Kelvin To Fahrenheit"},
    {"1. Kilometers per Hour To Miles per Hour", "2. Miles per Hour To Kilometers per Hour"},
    {"1. Lightyears to Kilometers", "2. Kilomters to Lightyears", "3. Meters to Feet", "4. Feet to Meters", "5. Centimeters to Inches", "6. Inches to Centimeters"},
    {"1. Kilograms to Pounds", "2. Pounds to Kilograms"},
    {"1. Liter per 100 Kilometer to Miles per Gallon", "2. Miles per Gallon to Liters per 100 Kilometers"}
  };
  //max in numOfOpts = 6
  string chText[numOfConvOpts][6][2] = {
    {
    {"degrees Celsius", "degrees Fahrenheit"},
    {"degrees Fahrenheit", "degrees Celsius"},
    {"degrees Celsius", "Kelvin"},
    {"Kelvin", "degrees Celsius"},
    {"degrees Fahrenheit", "Kelvin"},
    {"Kelvin", "degrees Fahrenheit"}
    },
    {
    {"kilometers per hour", "miles per hour"},
    {"miles per hour", "kilometers per hour"},
    },
    {
    {"lightyears", "kilometers"},
    {"kilometers", "lightyears"},
    {"meters", "feet"},
    {"feet", "meters"},
    {"centimeters", "inches"},
    {"inches", "centimeters"},
    },
    {
    {"kilograms", "pounds"},
    {"pounds", "kilograms"},
    },
    {
    {"liters per 100 km", "miles per gallon"},
    {"miles per gallon", "liters per 100 km"},
    }
  };
  cout << "Please choose converter:" << endl;

  for(int i = 0; i < numOfOpts[choiceOfConverter-1]; i++)
  {
    cout << opts[choiceOfConverter-1][i] << endl;
  }

  cout << "Your choice: ";
  cin >> choiceOfConversion;

  if(choiceOfConversion > numOfOpts[choiceOfConverter-1] || choiceOfConversion < 1)
  {
    return;
  }

  cout << "Enter " << measureName[choiceOfConverter-1] << " in " << chText[choiceOfConverter-1][choiceOfConversion-1][0] << ": ";
  cin >> start;
  value = converters[choiceOfConverter-1](start, choiceOfConversion);
  cout << start << " " << chText[choiceOfConverter-1][choiceOfConversion-1][0] << " ";
  cout << value;
  cout << " is " << chText[choiceOfConverter-1][choiceOfConversion-1][1] <<"." << endl;
}

int main()
{
  converter(getChoiceOfConv());

  return 0;
}
