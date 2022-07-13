run: main.o CarRating.o CarRatingService.o TreeNode.o
	g++ -o run main.cpp CarRating.o CarRatingService.o TreeNode.o

main.o: main.cpp CarRating.hpp CarRatingService.hpp
	g++ -c main.cpp

CarRating.o: CarRating.cpp
	g++ -c CarRating.cpp

CarRatingService.o: CarRatingService.cpp CarRating.hpp TreeNode.hpp
	g++ -c CarRatingService.cpp

TreeNode.o: TreeNode.cpp CarRating.hpp
	g++ -c TreeNode.cpp
