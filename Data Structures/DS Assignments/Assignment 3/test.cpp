#include "pch.h"
#include "../solA3/Header.h" // include header file here
using namespace std;

#include <fstream>
#include <string>


TEST(testNTreeCreation, InputFileReadingTest) // 10 marks
{
	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "LevelOrderOutput.txt";

	createTree(inputFilePath);
	levelOrderFunction(outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();

}


TEST(insertFile, insertFileTest) { // 5 marks
	
	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "InsertFileOutput.txt";
	string source = "testcase.txt";
	string targetPath = "/root/bin/apt-get";
	
	createTree(inputFilePath);
	insertFileFolder(source, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}
			
			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}
			
 			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(insertFolder, insertFolderTest) { // 5 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "InsertFolderOutput.txt";
	string source = "testcase";
	string targetPath = "/usr/dev";

	createTree(inputFilePath);
	insertFileFolder(source, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(insertFolderFail, insertFolderFailTest) { // 5 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "LevelOrderOutput.txt";
	string source = "testcase";
	string targetPath = "/usr/dev/echo.txt";

	createTree(inputFilePath);
	insertFileFolder(source, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(deleteFile, deleteFileTest) { // 5 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "DeleteFileOutput.txt";
	string targetPath = "/root/bin/ls.cpp";

	createTree(inputFilePath);
	deleteFileFolder(targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(deleteFolder, deleteFolderTest) { // 5 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "DeleteFolderOutput.txt";
	string targetPath = "/home/Desktop/Assignments";

	createTree(inputFilePath);
	deleteFileFolder(targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(mergeFolder, mergeFolderTest) { // 20 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "MergeFolderOutput.txt";
	string sourcePath = "/home/Desktop/Assignments";
	string targetPath = "/root/bin/apt-get";

	createTree(inputFilePath);
	mergeFolder(sourcePath, targetPath, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(searchFile, searchFileTest) { // 5 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "SearchFileOutput.txt";
	string targetFile = "Test.cpp";

	createTree(inputFilePath);
	searchFileFolder(targetFile, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}

TEST(searchFolder, searchFolderTest) { // 5 marks

	string inputFilePath = "input.txt";
	string outputFilePath = "<complete file path required>"; // file must be created in solution folder
	string expectedFilePath = "SearchFolderOutput.txt";
	string targetFolder = "lib";

	createTree(inputFilePath);
	searchFileFolder(targetFolder, outputFilePath);

	ifstream outputFile(outputFilePath);
	ifstream expectedFile(expectedFilePath);
	if (!outputFile.is_open() || !expectedFile.is_open())
	{
		if (!outputFile.is_open()) {
			cout << outputFilePath << " File Not Found" << endl;
		}
		if (!expectedFile.is_open()) {
			cout << expectedFilePath << " File Not Found" << endl;
		}
		ASSERT_TRUE(false);
	}
	else
	{
		string org, res;
		while (1)
		{
			if (expectedFile.eof() && outputFile.eof()) {
				break;
			}
			if (expectedFile.eof()) {
				org = "";
			}
			else {
				expectedFile >> org;
			}

			if (outputFile.eof()) {
				res = "";
			}
			else {
				outputFile >> res;
			}

			EXPECT_EQ(org, res);
		}

	}
	outputFile.close();
	expectedFile.close();
}