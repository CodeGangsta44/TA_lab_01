#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
  ifstream fin(argv[1]);
  ofstream fout("ip71_dovhopoliuk_01_output.txt");
  int len;
  fin>>len;
  int *arr = new int(len);
  for(int i = 0; i < len; i++){
    fin>>arr[i];
  }
  int count_of_even_elements = 0;
  for (int counter = 0; counter < len; counter++){
    if (arr[counter] % 2 ==  0){
      int swap = arr[counter];
      count_of_even_elements++;
      bool index_fought = false;
      for (int i = counter - 1; !index_fought && i>= 0;){
        if (arr[i] < swap && arr[i] % 2 == 0){
          index_fought = true;
          break;
        }
        arr[i + 1] = arr[i];
        arr[i] = swap;
        i--;
      }
    }
  }
  for (int counter = count_of_even_elements - 1; counter < len; counter++){
    int swap = arr[counter];
    int i = counter - 1;
    for (i; arr[i] < arr[i + 1] && i >= count_of_even_elements;){
      arr[i + 1] = arr[i];
      arr[i] = swap;
      i--;
    }
  }
  for (int counter = 0; counter < len; counter++){
    fout<<arr[counter]<<endl;
  }
}
