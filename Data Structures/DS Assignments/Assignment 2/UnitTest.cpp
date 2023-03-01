#include "gtest/gtest.h"
#include "SoundCloud.h"

//Global Data Structures
MMD<int, string, float> * mmd;
AMD<int, string> * amd;
AD<int, string, float> * ad;
ADP<int> * adp;

/*
	* TC1: Creating Music Metadata Database.
	* (Testing on first 12 entries)
*/
TEST(SoundCloudTesting, MusicMetadataDatabase)
{
	string path = "give path of Music.csv file";
	mmd = Create_MMD<int, string, float>(path); //function to be implemented

	int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //expected mbid(s)

	MMD<int, string, float> * current = mmd->next;
	for (int i = 1; i < 11; i++)
	{
		EXPECT_EQ(expected[i-1], current->previous->mbid);
		EXPECT_EQ(expected[i], current->mbid);
		EXPECT_EQ(expected[i+1], current->next->mbid);

		current = current->next;
	}
}

/*
	* TC2: Creating Author Metadata Database. 
	* (Testing on all entries)
*/
TEST(SoundCloudTesting, AuthorMetadataDatabase)
{
	string path = "give path of Authors.csv file";
	amd = Create_AMD<int, string>(path); //function to be implemented

	int expected[] = { 1, 2, 3, 4, 5 }; //expected aid(s)

	AMD<int, string> * current = amd;
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(expected[i], current->aid);

		current = current->next;
	}

	EXPECT_EQ(1, current->aid);
}

/*
	* TC3: Creating Album Database.
	* (Testing on first 2 albums data)
	* Note: You need to create 2-way relationships b/w MMD and AMD!
*/
TEST(SoundCloudTesting, AlbumDatabase)
{
	string path = "give path of Albums.csv file";
	ad = Create_AD<int, string, float>(path); //function to be implemented

	int expected_albums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 }; //expected abid(s)

	//Testing AD Data structure
	AD<int, string, float> * current = ad;
	for (int i = 0; i < 13; i++)
	{
		EXPECT_EQ(expected_albums[i], current->abid);

		current = current->next;
	}
	EXPECT_EQ(1, current->abid);

	//Testing 2-way relaionships b/w AD and MMD
	current = ad;
	current = current->next; //album 2

	Tracks<int> * expected_track = current->tracks->next; //track 2 in album 2 i.e: 14
	EXPECT_EQ(14, expected_track->trackRef->mbid); //testing direct access from AD to MMD

	MMD<int, string, float> * expected_music = mmd->next; //track 2 in MMD
	EXPECT_EQ(1, expected_music->album->abid); //testing direct access from MMD to AD

	//Testing 2-way relaionships b/w AD and AMD
	current = ad;
	current = current->next; //album 2

	AMD<int, string> * expected_author = current->author; //author of album 2 i.e: 1
	EXPECT_EQ(1, expected_author->aid); //testing direct access from AD to AMD

	AD<int, string, float> * expected_album = amd->albums->next; //author 1 (album 2) in AMD
	EXPECT_EQ(2, expected_album->abid); //testing direct access from AMD to AD
}

/*
	* TC4: Creating Author Discography Playlist.
	* (Testing against all entries)
	* Note: You need to create 2-way relationships b/w AD and AMD!
*/
TEST(SoundCloudTesting, AuthorDiscographyPlaylist)
{
	string path = "give path of Discography.csv file";
	adp = Create_ADP<int>(path); //function to be implemented

	int expected_adps[] = { 1, 2, 3, 4, 5 }; //expected abid(s)

	//Testing ADP Data structure
	ADP<int> * current = adp;
	for (int i = 0; i < 5; i++)
	{
		EXPECT_EQ(expected_adps[i], current->did);

		current = current->next;
	}
	EXPECT_EQ(1, current->did);

	//Testing 2-way relaionships b/w ADP and AD
	current = adp;
	current = current->next; //adp 2

	Albums<int> * expected_album = current->albums->next; //album 2 in ADP 2 i.e: 5 -> 2015
	EXPECT_EQ(5, expected_album->albumRef->abid); //testing direct access from ADP to AD

	AD<int, string, float> * expect_album = ad->next; //album 2 in AD
	EXPECT_EQ(1, expect_album->adp->did); //testing direct access from AD to ADP

	//Testing 2-way relaionships b/w ADP and AMD
	current = adp;
	current = current->next; //adp 2

	AMD<int, string> * expected_author = current->author; //author of ADP 2 i.e: 2
	EXPECT_EQ(2, expected_author->aid); //testing direct access from ADP to AMD

	expected_author = amd->next; //author 2 in AMD
	EXPECT_EQ(2, expected_author->adp->did); //testing direct access from AMD to ADP
}

/*
	* TC5: Search Music by MBID in MMD
	* (Testing on whole data)
*/
TEST(SoundCloudTesting, SearchMusicById)
{
	MMD<int, string, float> * result = Search_Music<int, string, float>(66); //function to be implemented

	EXPECT_EQ(66, result->mbid);
	EXPECT_EQ(6, result->album->abid);
	EXPECT_EQ(2, result->album->adp->did);
	EXPECT_EQ(2, result->album->author->aid);
}

/*
	* TC6: Search Author by AID in AMD
	* (Testing on whole data)
*/
TEST(SoundCloudTesting, SearchAuthorById)
{
	AMD<int, string> * result = Search_Author<int, string>(4); //function to be implemented

	EXPECT_EQ(4, result->aid);
	EXPECT_EQ(4, result->adp->did);
	EXPECT_EQ(10, result->albums->next->abid); //author's 4 album 2
	EXPECT_EQ(109, result->albums->next->tracks->next->trackRef->mbid); //author's 4 album 2, track 2 id
}

/*
	* TC7: Search Album by ABID in AD
	* (Testing on whole data)
*/
TEST(SoundCloudTesting, SearchAlbumById)
{
	AD<int, string, float> * result = Search_Album<int, string, float>(13); //function to be implemented

	EXPECT_EQ(13, result->abid);
	EXPECT_EQ(5, result->author->aid);
	EXPECT_EQ(5, result->adp->did);
	EXPECT_EQ(145, result->tracks->next->trackRef->mbid); //track 2 in album no. 13
}

/*
	* TC8: Search Discographies by DID in ADP 
	* (Testing on whole data)
*/
TEST(SoundCloudTesting, SearchAlbumById)
{
	ADP<int> * result = Search_Discography<int>(3); //function to be implemented

	EXPECT_EQ(3, result->did);
	EXPECT_EQ(3, result->author->aid);
	EXPECT_EQ(8, result->albums->next->albumRef->abid); //album 2
}

/*
	* TC9: Search Music by Album using ABID
	* (Testing on whole data)
*/
TEST(SoundCloudTesting, SearchMusicByAlbum)
{
	Tracks<int> * result = Search_Music_By_Album<int>(9); //function to be implemented

	int expected[] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 };

	int i = 0;
	while (result != NULL)
	{
		EXPECT_EQ(expected[i], result->trackRef->mbid);
		result = result->next;
		i++;
	}
}

/*
	* TC10: Search Music by Author using DID
	* (Testing on whole data)
*/
TEST(SoundCloudTesting, SearchMusicByAuthor)
{
	Albums<int> * result = Search_Music_By_Author<int>(4); //function to be implemented

	int expected_track1[] = { 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }; //album 9
	int expected_track2[] = { 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118 }; //album 10

	Tracks<int> * track1 = result->albumRef->tracks; //for album 1
	Tracks<int> * track2 = result->next->albumRef->tracks; //for album 2

	int i = 0;
	while (track1 != NULL)
	{
		EXPECT_EQ(expected_track1[i], track1->trackRef->mbid);
		track1 = track1->next;
		i++;
	}
	
	i = 0;
	while (track2 != NULL)
	{
		EXPECT_EQ(expected_track2[i], track2->trackRef->mbid);
		track2 = track2->next;
		i++;
	}
}
