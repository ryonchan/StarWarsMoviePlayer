#include "movie.h"
#include <stdexcept>
#include <sstream>

	// Function: Parameterized Constructor
	// Purpose: Sets member variables to input, clears list, and calls loader
	// Input: None
	// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
	mFilmName = filmName;
	currFrameNum = 1; //set to 0
	mFilm.clear(); //clear list
	loadTape();
	pos = mFilm.begin();
}

	// Function: Parameterized Constructor
	// Purpose: Sets member variables to input, clears list, and calls loader
	// Input: None
	// Returns: Nothing
MoviePlayer::~MoviePlayer() //destructor
{
	mFilm.clear(); //we’ll protectively ensure that the tape is empty here.
}

	// Function: goFwrd
	// Purpose: Moves the current "frame" forward by 1 frame
	// Also keeps track of how many frames have been viewed
	// Shouldn't go past the end of the movie
	// Input: None
	// Returns: Nothing
void MoviePlayer::goFwrd()
{
	if (currFrameNum != mFilm.size())
	{
		currFrameNum += 1;
		pos++;
	}
}

	// Function: goBack
	// Purpose: Moves the current "frame" backward by 1 frame
	// Also keeps track of how many frames have been viewed
	// Shouldn't go past the end of the movie
	// Input: None
	// Returns: Nothing
void MoviePlayer::goBack()
{
	if (currFrameNum != 1)
	{
		currFrameNum -= 1;
		pos--;
	}
}

	// Function: rewind
	// Purpose: Moves the current "frame" to the movie's beginning again
	// Input: None
	// Returns: Nothing
void MoviePlayer::rewind()
{
	currFrameNum = 1; //sets frame to beginning
	pos = mFilm.begin(); //changes the current position to beginning of film
}

	// Function: getCurrFrame
	// Purpose: Gets the string that contains the current "frame" as stored
	// in the list "mFilm"
	// Input: None
	// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
	return *pos; //dereferenced
}

	// Function: delCurrFrame
	// Purpose: Deletes the current frame, moves forward to the next one
	// Also keeps track of how many frames have been viewed
	// Input: None
	// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
	if(currFrameNum != mFilm.size())
	{
		pos = mFilm.erase(pos);
	}
	
}

	// Function: copyCurrFrame
	// Purpose: Copies current frame and places the copy BEFORE the current frame
	// Also keeps track of how many frames have been viewed
	// Input: None
	// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
	mFilm.insert(pos, *pos);
	pos--;
}

	// Function: getCurrFrameNum
	// Purpose: Gets the "index" that corresponds to the current frame
	// Input: None
	// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
	return currFrameNum;
}

	// Function: getNumFrames
	// Purpose: Gets the total number of frames in the movie
	// Input: None
	// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
	return mFilm.size();
}

	// Function: getFrameSize
	// Purpose: Gives the number of lines in a frame
	// For how big the "screen" for the film should be
	// Input: None
	// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
	return FRAMESIZE;
}

	// Function: load_tape
	// Purpose: Uses mFilmName (set by constructor) to fill
	// mFilm with strings that make up the movie to display
	// Input: None
	// Returns: Nothing
void MoviePlayer::loadTape()
{
    std::ifstream inFile(mFilmName);
    std::string num;
    std::string frame;
    std::string line;

    if (!inFile.is_open())
    {
        throw std::invalid_argument("error: file not found");
    }

    while (!inFile.eof())
    {
		std::getline(inFile, num); 
        if (num == "") 
        {
            break;
        }
        frame = "";

        for (unsigned i = 0; i < FRAMESIZE; i++)
        {
            std::getline(inFile, line);
            if (!line.empty() && line.back() == '\\')
            {
                line += " ";
            }
            frame += line + '\n';
        }

        int count = 0;
        std::stringstream ss(num);
        ss >> count;

        for (int i = 0; i < count; i++)
        {
            mFilm.push_back(frame);
        }

    }

    pos = mFilm.begin();
}


//Some input files have problematic input. In particular, a line may end with a backslash “\”. 
//This can be a problem. You can try getting around by adding white space to the end of the string ending in the backslash

//Some input files have other pieces of problematic input.
//Make sure that if the file ends with a partial or problematic frame don't add it to the linked list

//Some input files have a few empty frames. These may just be empty lines, but should still be a frame 
//and display a blank screen. Be sure your code detects empty lines appropriately in the loadTape function.
