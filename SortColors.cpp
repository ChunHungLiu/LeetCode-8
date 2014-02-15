class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, white = 0;
        
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) { ++red; }
            else if (A[i] == 1) { ++white; }
        }
        
        for (int i = 0; i < n; ++i) {
            if (red > 0) { A[i] = 0; --red; }
            else if (white > 0) { A[i] = 1; --white; }
            else { A[i] = 2; }
        }
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n-1;
        int non_white = -1;

        while (red < blue) {
            while (A[red] == 0 && red < blue) { ++red; }
            while (A[blue] == 2 && red < blue) { --blue; }
            if (red >= blue) return;
            
            if (A[red] == 2 || A[blue] == 0) { 
                swap(A[red], A[blue]); 
            } else { // both are white
                non_white = max(non_white, red+1);
                bool done = true;
                while (non_white < blue) {
                    if (A[non_white] == 0) {
                        swap(A[red], A[non_white]);
                        ++red; ++non_white;
                        done = false; 
                        break;
                    } else if (A[non_white] == 2) {
                        swap(A[blue], A[non_white]);
                        --blue; ++non_white;
                        done = false; 
                        break;
                    }
                    ++non_white;
                }

                if (done) return;
            }
        }
    }
};

//  one pass
// http://en.wikipedia.org/wiki/Dutch_national_flag_problem
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int red = -1;
        int blue = n;
        
        for (int i = 0; i < blue;) {
            if (A[i] == 0) { swap(A[i++], A[++red]); }
            else if (A[i] == 2) { swap(A[i], A[--blue]); }
            else { i++; }
        }
        
        return; 
    }
};
