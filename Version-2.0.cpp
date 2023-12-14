#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define Adress_Input "E:\\Aidin-Computer\\Desktop\\Sadjad-Uni\\Lessons\\My-Terms\\Term 7\\Computational-Intelligence\\Homeworks\\My-Answers\\HW1\\HW1-Computational_Intligense\\HW1-Computational_Intligense\\Input.txt"
//#define Adress_Input "E:\\Input.txt"
using namespace std;


class file_entery
{
public:
	file_entery() {}
	~file_entery() { arr.clear(); }
	void read_file()
	{
		int i, j, comma_pos, n;
		ifstream In_file(Adress_Input, ios::in);
		string LINE;
		if (!In_file) //Coudn't read file entery.
			throw;
		getline(In_file, LINE);
		row = stoi(LINE);
		getline(In_file, LINE);
		col = stoi(LINE);
		arr.resize(row, vector<int>(col));	
		getline(In_file, LINE);
		weights.resize(col);
		for (i = 0; i < col; i++) {
			comma_pos = LINE.find(',');
			weights[i] = stof(LINE.substr(0, comma_pos));
			LINE = LINE.substr(comma_pos + 1);
		}
		for (i = 0; i < row; i++) {
			getline(In_file, LINE);
			for (j = 0; j < col; j++) {
				comma_pos = LINE.find(',');
				arr[i][j] = stoi(LINE.substr(0, comma_pos));
				LINE = LINE.substr(comma_pos + 1);
			}
		}
		getline(In_file, LINE);
		threshold = stof(LINE);
	}
	void show_arr()
	{
		cout << "Weights are : " << endl;
		for (int i = 0; i < col; i++) {
			cout << weights[i] << ", ";
		}
		cout << endl;
		cout << "Array has : " << row << " row & " << col << " column. " << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << arr[i][j] << ", ";
			}
			cout << endl;
		}
	}
	vector<float> get_weights() { return weights; }
	vector<vector<int>> get_array_entry() { return arr; }
	float get_threshold() { return threshold; }
	int get_row() { return row; }
	int get_col() { return col; }
private:
	int row, col;
	float threshold;
	vector<vector<int>> arr;
	vector<float> weights;
};

/*class file_output {
public:
	file_output(vector<vector<int>> _arr) { arr = _arr; }


private:
	vector<vector<int>> arr;

};*/

int main() {
	file_entery f;
	int tries = 3;

	while (tries > 0)
	{
		try {
			f.read_file();
			f.show_arr();
			break;
		}
		catch (...)
		{
			cout << "There are some problems try to solve them.(you can try again " << --tries << "times. " << endl;
			system("pause");
		}
	}
	vector<float> weights = f.get_weights();
	vector<vector<int>> arr = f.get_array_entry();
	float threshold = f.get_threshold();
	int row = f.get_row(), col = f.get_col();
	vector<float> resualt(row);
	for (int i = 0; i < row; i++) {
		resualt[i] = 0;
		for (int j = 0; j < col; j++) {
			resualt[i] += (float) arr[i][j] * weights[j];
		}
		cout << resualt[i];
		if (threshold > resualt[i])
			cout << "(Non activated)" << endl;
		else cout << "(Activated)" << endl;
	}
	
	return 0;
}
