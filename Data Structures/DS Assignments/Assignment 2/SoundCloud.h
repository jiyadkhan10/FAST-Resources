#include <iostream>
using namespace std;

//Music Metadata DataBase (A doubly linked list)
class MMD
{
	public:
		//data members
		int mbid;
		AD* album;

		//connections
		MMD* next;
		MMD* previous;
};

//Author Metadata DataBase (A circular linked list)
class AMD
{
	public:
		//data members
		int aid;
		AD* albums;
		ADP* adp;

		//connections
		AMD* next;
};

//Tracks (A singly linked list)
class Tracks
{
	public:
		//data members
		int trackNumber;
		MMD* trackRef;

		//connections
		Tracks* next;
};

//Album DataBase (A circular linked list)
class AD
{
	public:
		//data members
		int abid;
		AMD* author;
		Tracks* tracks;
		ADP* adp;

		//connections
		AD* next;
};

//Albums (A singly linked list)
class Albums
{
	public:
		//data members
		int year;
		AD* albumRef;

		//connections
		Albums* next;
};

//Author Discography Playlist (A circular linked list)
class ADP
{
	public:
		//data members
		int did;
		AMD* author;
		Albums* albums;

		//connections
		ADP* next;
};

//Functions Prototypes
MMD* Create_MMD(string path); //should return head of the MMD linkedlist
AMD* Create_AMD(string path); //should return head of the AMD linkedlist
AD* Create_AD(string path); //should return head of the AD linkedlist
ADP* Create_ADP(string path); //should return head of the ADP linkedlist
MMD* Search_Music(int MBID); //should return pointer to track having mbid = MBID
AMD* Search_Author(int AID); //should return pointer to author having aid = AID
AD* Search_Album(int ABID); //should return pointer to album having abid = ABID
ADP* Search_Discography(int DID); //should return pointer to discography having did = DID
Tracks* Search_Music_By_Album(int ABID); //should return singly linklist of "Tracks" in given album
Albums* Search_Music_By_Author(int DID); //should return singly linklist of "Albums" in given discography