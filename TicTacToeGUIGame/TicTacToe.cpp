#include <SFML/Graphics.hpp>
#include <vector>

//This will use sfml graphics and will require the download of the sfml library
//Andrea Bonato

bool filledVal[9]; //this will keep track of the available 
int turn = 0; //0evem for O and odd for X ... when the click count turns to 9, then everything must be turned to white again
sf::RenderWindow window(sf::VideoMode(720,720), "~TicTacToe~"); //Renders window and opens it at size 1024 by 720
//title "~TicTacToe~"
int xVal[9] = {0};	//This wil hold the values to check who wins
int oVal[9] = {0};

//This will check the squares for the logic
bool checkWin (int Val[])
{
	if(Val[0] == Val[1] && Val[2] == 1 && Val[1] == Val[2])
	{
	
	}else if (Val[3] == Val[4] && Val[5] == 1 && Val[4] == Val[5]) {
		
		return true;

	}else if (Val[6] == Val[7] && Val[8] == Val[7] && Val[7] == 1) {
		
		return true;

	}else if (Val[0] == Val[4] && Val[4] == Val[8] && Val[8] == 1) {
		
		return true;

	}else if (Val[2] == Val[4] && Val[4] == Val[6] && Val[6] == 1) {
		
		return true;

	}else if (Val[0] == Val[3] && Val[3] == Val[6] && Val[6] == 1) {
		
		return true;

	}else if (Val[1] == Val[4] && Val[4] == Val[7] && Val[7] == 1) {
		
		return true;

	}else if(Val[2] == Val[5] && Val[5] == Val[8] && Val[8] == 1){
	
		return true;
	}else{

		return false;
	}
}

void checkVal(int count, sf::RectangleShape &rectangleArray, sf::RectangleShape &lineVal1, sf::RectangleShape &lineVal2, sf::CircleShape &circleArray)
{	
	//This will find he rectangle at the given position
	sf::IntRect rect(rectangleArray.getPosition().x,
				rectangleArray.getPosition().y,
				rectangleArray.getGlobalBounds().width,
				rectangleArray.getGlobalBounds().height);
		

		//Check if the mouse is clicking the rectangle
		if(rect.contains(sf::Mouse::getPosition(window)))
		{	
			//figure out whose turn it is
			if(turn%2 == 0)
			{

				if(filledVal[count])
				{
					//do nothing									}
			
				}		
				else
				{	
					//change color of shape
					filledVal[count] = true;
					circleArray.setOutlineColor(sf::Color(255,0,0));
					oVal[count] = 1;
					count++;
					turn++;
				}

			}
			else
			{
			
				if(filledVal[count])
				{
					//do nothing
				}
				else
				{	
					//change color of shape`
					filledVal[count] = true;
					lineVal1.setFillColor(sf::Color(255,0,0));
					lineVal2.setFillColor(sf::Color(255,0,0));
					xVal[count] = 1;
					count++;
					turn++;
				}	
		
			}
			
			return;
				
		}	


}

int main ()
{
	//Everything will be defined here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`~~~	

	std::vector<sf::RectangleShape> rectangleArray;
	float posx = 5.f, posy = 5.f;

	for (int i = 0; i < 9; i++)
	{
		filledVal[i] = false;
		xVal[i] = 0;
		oVal[i] = 0;
	}
	//create the board 3 by 3 square
	
	for(int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3;  k++)
		{	
			sf::RectangleShape rectangle(sf::Vector2f(230.f,230.f));
			rectangle.setFillColor(sf::Color(255,255,255));
			rectangle.setOutlineThickness(10.f);
			rectangle.setOutlineColor(sf::Color(50,50,50));
			rectangle.setPosition(posx, posy);
			posx += 240.f;
			rectangleArray.push_back(rectangle);
		}

		posx = 5.f;
		posy += 240.f;
	}	
	posx = 70.f;
	posy = 160.f;

	//making the X
	
	std::vector<sf::RectangleShape> lineVal1;	// /
	std::vector<sf::RectangleShape> lineVal2;	// \

	for (int i = 0; i < 3; i++)
	{
		for(int k = 0; k < 3; k++)
		{	
			sf::RectangleShape lineDown(sf::Vector2f(150.f, 10.f));
			lineDown.rotate(45.f);

			sf::RectangleShape lineUp(sf::Vector2f(150.f, 10.f));
			lineUp.rotate(315.f);
	
			lineDown.setFillColor(sf::Color(255,255,255)); //change to 255 0 0 when selected
			lineUp.setFillColor(sf::Color(255,255,255));
		
			lineUp.setPosition(posx, posy);
			lineDown.setPosition(posx, posy-105.f);
				
			//When instantiating lineUp, we must do the same to the line down
			
			lineVal1.push_back(lineUp);
			lineVal2.push_back(lineDown);

			posx += 240;
		
		}

		posx = 70.f;
		posy += 240;
	}

	//must draw both lines / + \ = X

	//making the O
	
	std::vector<sf::CircleShape> circleArray;

	posx = 40.f;
	posy = 40.f;

	for(int  i = 0 ; i < 3; i++)
	{
		for(int k = 0; k < 3; k++)
		{	
			sf::CircleShape oChar(80.f);
			//start out white, then change color
			oChar.setFillColor(sf::Color(255,255,255));
			oChar.setOutlineThickness(10.f);
			oChar.setOutlineColor(sf::Color(255,255,255)); //change to 255 0 0 when clicked
			oChar.setPosition(posx,posy);			
			
			circleArray.push_back(oChar);

			posx += 240.f;
		}

		posx = 40.f;
		posy += 240.f;
	}
	//event stuff
	while (window.isOpen()) //game/window loop --> while window is open
	{
		sf::Event event; //Create event object, namespae sf

		
		while(window.pollEvent(event))	//check if there are any events
		{
			if (event.type == sf::Event::Closed)	//If someone clicks the x in the top corner
			{
				window.close();	//Close window
			}

			//events under here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			
			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{					
					//TODO: FIX THIS. find out how to find where the mouse position is relatvie to any of the rectangle
					for(int i = 0; i < 9; i++)
						checkVal(i, rectangleArray.at(i), lineVal1.at(i), lineVal2.at(i), circleArray.at(i)); //checks availibility for shape and color shapes					
				}
			}

			//TODO: ADD AN EVENT TO SET VALUE TO VISIBLE WHEN CLICKED
		
		}
	
		//general logic and stuff goes here ~~~~~~~~~~~~~~~~~~~~~~~~~
		

		//Set all the colors to white when 9 cicks have been made
		if(turn == 9 || checkWin(oVal) || checkWin(xVal))
		{
			turn = 0;
			for(int i = 0; i < 9; i++)
			{
				circleArray.at(i).setOutlineColor(sf::Color(255,255,255));
				lineVal1.at(i).setFillColor(sf::Color(255,255,255));
				lineVal2.at(i).setFillColor(sf::Color(255,255,255));
				filledVal[i] = false;
				xVal[i] = 0;
				oVal[i] = 0;
			}
		}
		
		window.clear(sf::Color(50,50,50)); //remove all -->blanks butter
	
		//draw everything here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		for (int i = 0; i < 9; i++)
		{
			window.draw(rectangleArray.at(i));
			window.draw(circleArray.at(i));
			window.draw(lineVal1.at(i));
			window.draw(lineVal2.at(i));

		}
		
	
		window.display(); //takes what is in the buffer and pushes it to the screen

	}

	return 0;
}
