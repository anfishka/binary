
class BinaryTree
{
	
private:
	class Branch
	{
	public:
		int data;
		Branch* leftBranch;
		Branch* rightBranch;

	};

public:
	Branch* headBranch;

	void addBranch(int val, Branch*& headBranch)
	{
		if (!headBranch)
		{
			headBranch = new Branch;
			headBranch->data = val;
			headBranch->leftBranch = nullptr;
			headBranch->rightBranch = nullptr;
		}
		else
		{
			if (headBranch->data > val)
			{
				addBranch(val, headBranch->leftBranch);
			}
			else
			{
				addBranch(val, headBranch->rightBranch);
			}
		}
	}

	void clearTree(Branch* headBranch)
	{
		if (!headBranch) return;
		clearTree(headBranch->leftBranch);
		clearTree(headBranch->rightBranch);


		delete headBranch;
		return;

	}

	int lines = 0;
	void printTree(Branch* headBranch)
	{
		if (!headBranch) return;
		lines++;

		printTree(headBranch->leftBranch);
		for (int i = 0; i < lines; i++)
			std::cout << " ";
		std::cout << headBranch->data << "\n";
		printTree(headBranch->rightBranch);

		lines--;
		return;

	}


};

int main()
{
	BinaryTree demoTree;

		demoTree.addBranch(1, demoTree.headBranch);
		demoTree.addBranch(2, demoTree.headBranch);
		demoTree.addBranch(90, demoTree.headBranch);
		demoTree.addBranch(891, demoTree.headBranch);
		demoTree.addBranch(92, demoTree.headBranch);
		demoTree.addBranch(7, demoTree.headBranch);

	

		demoTree.printTree(demoTree.headBranch);

		demoTree.clearTree(demoTree.headBranch);

	return 0;
}
