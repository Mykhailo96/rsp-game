/***************************************************************************
 * rps_game - Rock, Paper, Scissors Game                                   *
 *                                                                         *
 * Copyright (C) 2015  PLLUG.Community   (info@pllug.org.ua)               *
 *                                                                         *
 * This program is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ***************************************************************************/

#include <iostream>
#include <algorithm>

/*!
 * \brief The Level enum
 */
enum Level
{
    UNSPECIFIED = 0,
    EASY,
    NORMAL,
    HARD
};

const std::string cArgKeyLevel = "--level";
const std::string cArgKeyVersion = "--version";

const std::string cLevelStringEasy = "easy";
const std::string cLevelStringNormal = "normal";
const std::string cLevelStringHard = "hard";

/*!
 * \brief showHelp
 */
void showHelp()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "  rps_game [options]" << std::endl;
    std::cout << "      --level (EASY|NORMAL|HARD)" << std::endl;
    std::cout << "          specify game difficulty (argument is required)" << std::endl;
    std::cout << "      --version" << std::endl;
    std::cout << "          output programm version" << std::endl;
}

/*!
 * \brief parseLevel
 * \param levelString
 * \return
 */
Level parseLevel(std::string levelString)
{
    Level rLevel = UNSPECIFIED;

    std::transform(levelString.begin(), levelString.end(), levelString.begin(), ::tolower);

    if (cLevelStringEasy == levelString)
    {
        rLevel = EASY;
    }
    else if (cLevelStringNormal == levelString)
    {
        rLevel = NORMAL;
    }
    else if (cLevelStringHard == levelString)
    {
        rLevel = HARD;
    }

    return rLevel;
}

/*!
 * \brief findArgPosition
 * \param argc
 * \param argv
 * \param argName
 * \return
 */
int findArgPosition(int argc, char* argv[], const std::string &argName)
{
    int rPosition = -1;

    for (int argIndex = 1; argIndex < argc; ++argIndex)
    {
        std::string nextArg = argv[argIndex];
        std::transform(nextArg.begin(), nextArg.end(), nextArg.begin(), ::tolower);

        if (argName == nextArg)
        {
            rPosition = argIndex;
        }
    }

    return rPosition;
}

/*!
 * \brief stringArg
 * \param argc
 * \param argv
 * \param argName
 * \return
 */
std::string stringArg(int argc, char* argv[], std::string argName)
{
    std::string result;

    int argIndex = findArgPosition(argc, argv, argName);

    if (-1 != argIndex)
    {
        if (argIndex + 1 < argc)
        {
            result = argv[argIndex + 1];
        }
    }

    return result;
}

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        showHelp();
        return 1;
    }

    // Parse level
    Level level = UNSPECIFIED;

    std::string levelStr = stringArg(argc, argv, cArgKeyLevel);
    if (!levelStr.empty())
    {
        level = parseLevel(levelStr);
    }

    if (UNSPECIFIED == level)
    {
        showHelp();
        return 1;
    }

    std::cout << level << std::endl;

    return 0;
}


