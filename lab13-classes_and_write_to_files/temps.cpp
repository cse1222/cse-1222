/**
 * @file temps.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program will collect from the user a list of temperature samples taken throughout a
 * single day. Each temperature sample consists of a temperature (degrees Fahrenheit) and a time
 * (military time in hours and minutes only). The hours in military time is an integer between 0
 * and 23 and the minutes is an integer between 0 and 59. The program will write this information
 * into a file defined by the user and display military time in the format HH:MM, where HH is the
 * hour and MM is the minutes.
 * @version 0.1
 * @date 2016-12-06
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief Class to model the clock time in military time.
 * 
 */
class MilTime {
    private:
        int hour;           // hours of time (military time)
        int minutes;        // minutes of time (military time)

    public:
        // Member functions
        void setHour(const int h);
        void setMin(const int m);

        int getHour() const;
        int getMin() const;

        void write_out(ofstream &fout) const;

        MilTime();    // default constructor
};

/**
 * @brief Construct a new MilTime object (default).
 * 
 */
MilTime::MilTime() {
    hour = 0;
    minutes = 0;
}

/**
 * @brief Class to model a temperature sample.
 * 
 */
class Fahrenheit {
    private:
        double degree;          // temperature in degrees (Fahrenheit)
        MilTime time;           // time of sample in military time

    public:
        // Member functions
        void setTemp(const double temp);
        void setTime(const int h, const int m);

        double getTemp() const;
        MilTime getTime() const;
        double getCelsius() const;

        void write_out(ofstream &fout) const;

        Fahrenheit();    // default constructor
};

/**
 * @brief Construct a new Fahrenheit object.
 * 
 */
Fahrenheit::Fahrenheit() {
    degree = 0;
    time = MilTime();
}

/* FUNCTION PROTOTYPES */
string read_filename(const string prompt);
int read_num_samples(const string prompt);
Fahrenheit read_sample(const int k);
double average_temp(const vector<Fahrenheit> &samples);
double coldest_temp(const vector<Fahrenheit> &samples);
MilTime last_sample(const vector<Fahrenheit> &samples);
void write_to_file(const string fileName, const vector<Fahrenheit> &samples);

int main() {
    string fname;                   // Output file name
    int n;                          // Number of temperature samples
    vector<Fahrenheit> temps;       // Temperature samples

    /* Prompt for the name of the output file to write */
    fname = read_filename("Enter the output file name: ");

    /* Prompt for the number of temperature samples */
    n = read_num_samples("Enter the number of samples: ");

    /* Read temperature samples from user */
    for (int i = 0; i < n; i++) {
        cout << endl;
        temps.push_back(read_sample(i+1));
    }

    /* Write the sample information to the output file */
    write_to_file(fname, temps);

    return 0;
}

/* FUNCTION DEFINITIONS */

/**
 * @brief Prompts and reads in a file name.
 * 
 * @param prompt Prompt displayed to user
 * @return The entered file name as a string. 
 */
string read_filename(const string prompt) {
    string fileName;
    cout << prompt, cin >> fileName;
    return fileName;
}

/**
 * @brief Prompts and reads in a the number of temperature samples (degree and time) that
 * the user will enter.
 * 
 * @param prompt Prompt displayed to user
 * @return The number of tempertaure samples.
 */
int read_num_samples(const string prompt) {
    int numSamples;
    cout << prompt, cin >> numSamples;
    return numSamples;
}

/**
 * @brief Prompts and reads in a single temperature samples (degree and time).
 * the user will enter.
 * 
 * @param k The sample number
 * @return The temperature sample (degree and time) object. 
 */
Fahrenheit read_sample(const int k) {
    double temp;
    int hour, min;
    Fahrenheit sample;

    /* Prompt and read in temperature sample characteristics */
    cout << "SAMPLE #" << k << endl;
    cout << "Enter degrees (Fahrenheit): ", cin >> temp;
    cout << "Enter hours (Military time): ", cin >> hour;
    cout << "Enter minutes (Military time): ", cin >> min;

    /* Set the attributes for the sample based on the user input */
    sample.setTemp(temp);
    sample.setTime(hour, min);

    return sample;
}

/**
 * @brief Computes the average temperature (Fahrenheit) over all the samples.
 * 
 * @param samples The vector of temperatue samples
 * @return The average temperature (F) of the samples. 
 */
double average_temp(const vector<Fahrenheit> &samples) {
    double avgTemp = 0;

    /* Check that at least one sample was taken */
    if (samples.size() > 0) {
        /* Sum the temperatures from each sample */
        for (int i = 0; i < samples.size(); i++) {
            avgTemp += samples[i].getTemp();
        }
        /* Divide sum of temps by number of samples to get average temp */
        avgTemp /= samples.size();
    }

    return avgTemp;
}

/**
 * @brief Computes the coldest temperature (Fahrenheit) over all the samples.
 * 
 * @param samples The vector of temperatue samples
 * @return The coldest temperature (F) of the samples.  
 */
double coldest_temp(const vector<Fahrenheit> &samples) {
    double minTemp = 0;

    /* Check that at least one sample was taken */
    if (samples.size() > 0) {
        /* Initialize coldest temp to that of first sample */
        minTemp = samples[0].getTemp();;
        for (int i = 1; i < samples.size(); i++) {
            /* Get the temperature (F) of the current sample */
            double temp = samples[i].getTemp();
            /* Check if current temperature sample is colder than current coldest */
            if (temp < minTemp) {
                minTemp = temp;
            }
        }
    }

    return minTemp;
}

/**
 * @brief Finds the time of the last sample taken during the day.
 * 
 * @param samples The vector of temperatue samples
 * @return The time of the last sample taken.  
 */
MilTime last_sample(const vector<Fahrenheit> &samples) {
    /* Initialize latest time to start of day */
    MilTime lastTime;
    lastTime.setHour(0);
    lastTime.setMin(0);

    /* Check that at least one sample was taken */
    if (samples.size() > 0) {
        for (int i = 0; i < samples.size(); i++) {
            /* Get the time of the current sample */
            MilTime time = samples[i].getTime();
            /* Check if current time is the latest recorded for the day */
            if (time.getHour() >= lastTime.getHour() && time.getMin() > lastTime.getMin()) {
                lastTime = time;
            }
        }
    }

    return lastTime;
}

/**
 * @brief Print all temperature sample information for the day to the requested output file.
 * 
 * @param fileName The name of the output file to print to
 * @param samples The vector of temperatue samples
 */
void write_to_file(const string fileName, const vector<Fahrenheit> &samples) {
    ofstream fout;

    /* Open the file output stream */
    fout.open(fileName.c_str(), ios::out);
    if (!fout.is_open()) {
        cerr << "ERROR: Unable to open file " << fileName << endl;
        exit(0);
    }

    /* Print the temperature samples taken for the day */
    fout << "-------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < samples.size(); i++) {
        fout << "Sample #" << i+1 << ": ";
        samples[i].write_out(fout);
        fout << endl;
    }
    fout << "-------------------------------------------------------------------------------------------------" << endl;

    /* Print the temperature sample statistics for the day */
    fout << "The average temp is " << average_temp(samples) << " degrees F" << endl;
    fout << "The coldest temp is " << coldest_temp(samples) << " degrees F" << endl;
    fout << "The last sample was taken at time ";
    last_sample(samples).write_out(fout);
    fout << endl;

    /* Close the file output stream */
    fout.close();
}

/* CLASS MEMBER FUNCTION DEFINITIONS */

/**
 * @brief Sets the current hour for the time (military time).
 * 
 * @param h The current hour
 */
void MilTime::setHour(const int h) {
    hour = h;
}

/**
 * @brief Sets the current minute for the time (military time).
 * 
 * @param m The current minute
 */
void MilTime::setMin(const int m) {
    minutes = m;
}

/**
 * @brief Gets the current hour for the time (military time).
 * 
 * @return The current hour.
 */
int MilTime::getHour() const {
    return hour;
}

/**
 * @brief Gets the current minute for the time (military time).
 * 
 * @return The current minute. 
 */
int MilTime::getMin() const {
    return minutes;
}

/**
 * @brief Prints the current military time in the format HH:MM to a given file output stream.
 * Assumes that the user will enter only valid values for hours (0,23) and minutes (0,59).
 * 
 * @param fout The output file stream
 */
void MilTime::write_out(ofstream &fout) const {
    if (hour < 10) {
        fout << 0;
    }
    fout << hour << ":";
    if (minutes < 10) {
        fout << 0;
    }
    fout << minutes;
}

/**
 * @brief Sets the recorded temperatire (Fahrenheit) for the sample.
 * 
 * @param temp The temperature in Fahrenheit
 */
void Fahrenheit::setTemp(const double temp) {
    degree = temp;
}

/**
 * @brief Sets the time that the sample was taken.
 * 
 * @param h The current hour
 * @param m The current minute
 */
void Fahrenheit::setTime(const int h, const int m) {
    time.setHour(h);
    time.setMin(m);
}

/**
 * @brief Gets the temperature recorded for the sample in Fahrenheit.
 * 
 * @return The sample temperature in Fahrenheit. 
 */
double Fahrenheit::getTemp() const {
    return degree;
}

/**
 * @brief Gets the time (military time) that the sample was taken.
 * 
 * @return The sample time (military time). 
 */
MilTime Fahrenheit::getTime() const {
    return time;
}

/**
 * @brief Gets the temperature recorded for the sample in Celcius.
 * 
 * @return The sample temperature in Celsius.
 */
double Fahrenheit::getCelsius() const {
    double celsius = (degree - 32) / 1.8;
    return celsius;
}

/**
 * @brief Prints the sample information (time taken and temp in F and C) to a given file
 * output stream.
 * 
 * @param fout The output file stream
 */
void Fahrenheit::write_out(ofstream &fout) const {
    fout << degree << " degrees F (or " << getCelsius() << " degrees C) at ";
    time.write_out(fout);
}
