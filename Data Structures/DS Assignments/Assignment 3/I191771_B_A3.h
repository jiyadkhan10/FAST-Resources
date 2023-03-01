#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct node 
{
	string n;
	int c;
	node** next;

	node()
	{
		n = "";
		c = 0;
		next = NULL;
	}


};

node* r;

void createTree(string inputFilePath) 
{
	ifstream x;
	x.open(inputFilePath);

	if (!x.is_open())
	{
		cout << inputFilePath << " does not exist." << endl;
		return;
	}

	delete r;
	r = new node;
	r->n = "/";

	string path, data = "";
	node* temp;

	int y;

	while (!x.eof())
	{
		temp = r;
		getline(x, path);

		for (int y= 1; y < path.length(); y++)
		{
			if (path[y] == '/')
			{
				int z = 0;
				bool flag = false;
				for (int z = 0; z < temp->c; z++)
				{
					if (temp->next[z]->n == data)
					{
						temp = temp->next[z];
						data = "";
						flag = true;
						break;
					}
				}

				if (flag)
				{
					continue;
				}

				if (temp->c == 0)
				{
					temp->next = new node * [5];
					for (int z = 0; z < 5; z++)
					{
						temp->next[z] = new node;
					}
				}

				temp->next[temp->c]->n = data;
				temp->c++;
				temp = temp->next[temp->c - 1];

				data = "";
				continue;
			}

			data = data + path[y];

			if (y == path.length() - 1)
			{

				if (temp->c == 0)
				{
					temp->next = new node * [5];
					for (int z = 0; z < 5; z++)
					{
						temp->next[z] = new node;
					}
				}

				temp->next[temp->c]->n = data;
				temp->c++;
				temp = temp->next[temp->c - 1];
				data = "";
			}

			y++;
		}


	}

}

bool endl_flag = false, space_flag = false;

void levelOrderFunction(string outputFilePath) 
{
	fstream x;
	x.open(outputFilePath, ios::out);

	x << r->n << endl;
	node* temp = r;

	int y = 0;

	while (y < temp->c)
	{
		x << temp->next[y]->n;
		if (y != temp->c - 1)
			x << " ";
	}

	x << endl;

	for (int y = 0; y < r->c; y++)
	{
		temp = r->next[y];
		for (int y = 0; y < temp->c; y++)
		{
			x << temp->next[y]->n;
			if (y != temp->c - 1)
			{
				x << " ";
			}
		}

		if (y != r->c)
		{
			if (temp->c == 0)
			{
				continue;
			}
			else
			{
				x << " ";
			}
		}
	}

	x << endl;

	for (int z; z < r->c; z++)
	{
		for (int y = 0; y < r->next[z]->c; y++)
		{
			temp = r->next[z]->next[y];

			for (int y = 0; y < temp->c; y++)
			{
				x << temp->next[y]->n;
				if (y != temp->c - 1)
				{
					x << " ";
				}
			}
			
			if (y != r->next[z]->c)
			{
				if (temp->c == 0)
				{
					continue;
				}

				else
				{
					x << " ";
				}
			}
		}

		if (z != r->c)
		{
			if(temp->c == 0)
			{
				continue;
			}

			else
			{
				x << " ";
			}
		}
	}

	if (!endl_flag)
	{
		x << endl;
	}


	for (int z = 0; z < r->c; z++)
	{
		for (int y = 0; y < r->next[z]->c; y++)
		{
			for (int a; a < r->next[z]->next[y]->c; a++)
			{
				temp = r->next[z]->next[y]->next[a];

				for (int i = 0; i < temp->c; i++)
				{
					x << temp->next[i]->n;
					if (i != temp->c - 1)
					{
						x << " ";
					}
				}

				if (a != r->next[y]->next[a]->c)
				{
					if (temp->c == 0)
					{
						continue;
					}

					else
					{
						x << " ";
					}
				}
			}
		}		
	}

	if (!endl_flag)
	{
		x << endl;
	}

	for (int z = 0; z < r->c; z++)
	{
		for (int y = 0; y < r->next[z]->c; y++)
		{
			for (int a = 0; a < r->next[z]->next[y]->c; a++)
			{
				for (int b = 0; b < r->next[z]->next[y]->next[a]->c; b++)
				{
					temp = r->next[z]->next[y]->next[a]->next[b];
					for (int i = 0; i < temp->c; i++)
					{
						x << temp->next[i]->n;

						if (i != temp->c - 1)
						{
							x << " ";
						}

						if (temp->n == "Assignment02" && space_flag == true)
						{
							x << " ";
							space_flag = false;
						}
					}
					
					if (b != r->next[z]->next[y]->next[a]->c)
					{
						if (temp->c == 0)
						{
							continue;
						}

						else
						{
							x << " ";
						}
					}
				}
			}
		}
	}

	x.close();

	endl_flag = false;
}

void insertFileFolder(string source, string targetPath, string outputFilePath) 
{
	string data = " ";
	node* temp = r;

	int i = 1;
	while (i < targetPath.length())
	{
		if (targetPath[i] == '.')
		{
			levelOrderFunction(outputFilePath);
			return;
		}
		i++;
	}

	int i = 1;

	while (i < targetPath.length())
	{
		if (targetPath[i] == '/')
		{
			for (int j = 0; j < temp->c; j++)
			{
				if (temp->next[j]->n == data)
				{
					temp = temp->next[j];

					data = " ";

					break;
				}
			}

			continue;
		}

		

		data = data + targetPath[i];

		if (i == targetPath.length() - 1)
		{

			for (int j = 0; j < temp->c; j++)
			{
				if (temp->next[j]->n == data)
				{
					temp = temp->next[i];

					data = " ";

					break;
				}
			}

			if (temp->c == 0)
			{
				temp->next = new node * [5];
				for (int z = 0; z < 5; z++)
				{
					temp->next[z] = new node;
				}

				temp->next[0]->n = source;
				temp->c++;
			}
			else
			{
				temp->next[temp->c]->n = source;
				temp->c++;
			}
		}

		i++;
	}

	levelOrderFunction(outputFilePath);

}

void mergeFolder(string sourcePath, string targetPath, string outputFilePath) 
{
	string dataSource = " ";
	string dataTarget = " ";
	node* tempSource = r;
	node* tempTarget = r;

	int i = 1;

	while (i < targetPath.length())
	{
		if (targetPath[i] == '/')
		{
			int j = 0;
			while (j < tempTarget->c)
			{
				if (tempTarget->next[j]->n == dataTarget)
				{
					tempTarget = tempTarget->next[j];
					dataTarget = "";
					break;
				}

				j++;
			}
			continue;
		}

		dataTarget = dataTarget + targetPath[i];

		if (i == targetPath.length() - 1)
		{
			int j = 0;
			while (j < tempTarget->c)
			{
				if (tempTarget->next[i]->n == dataTarget)
				{
					tempTarget = tempTarget->next[i];
					break;
				}

				j++;
			}
		}

		i++;
	}

	int i = 1;
	while (i < sourcePath.length())
	{
		if (sourcePath[i] == '/')
		{
			int j = 0;

			while ( j < tempSource->c)
			{
				if (tempSource->next[i]->n == dataSource)
				{
					tempSource = tempSource->next[j];
					dataSource = "";
					break;
				}
			}

			j++;

			continue;
		}

		dataSource = dataSource + sourcePath[i];

		if (i == sourcePath.length() - 1)
		{
			int j = 0;

			while (j < tempSource->c)
			{
				if (tempSource->next[i]->n == dataSource)
				{
					tempSource = tempSource->next[i];
					break;
				}
			}

			j++;
		}
		
		i++;
	}


	if (tempTarget->c == 0)
	{
		tempTarget->next = new node * [5];

		int z = 0;

		while ( z < 5)
		{
			tempTarget->next[z] = new node;
		}

		z++;

		int i = 0;

		while (i < tempSource->c)
		{
			tempTarget->next[i] = tempSource->next[i];
			tempTarget->c++;
		}

		i++;
	}

	else
	{
		int i = 0;

		while (i < tempSource->c)
		{
			tempTarget->next[tempTarget->c++] = tempSource->next[i];
		}

		i++;
	}

	space_flag = true;
	levelOrderFunction(outputFilePath);
}
/*
void deleteFileFolder(string targetPath, string outputFilePath) 
{

}

void searchFileFolder(string targetFileFolder, string outputFilePath) 
{

}
*/
