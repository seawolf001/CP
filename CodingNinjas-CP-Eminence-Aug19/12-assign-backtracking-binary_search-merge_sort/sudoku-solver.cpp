bool done(int arr[9][9], int& r, int& c) {
    for(r=0;r<9;r++) {
        for(c=0;c<9;c++) {
            if(arr[r][c]==0) return false;
        }
    }
    return true;
}

bool is_safe(int arr[9][9], int r, int c, int x) {
    for(int i=0;i<9;i++) { if(arr[r][i]==x) return false; }
    for(int i=0;i<9;i++) { if(arr[i][c]==x) return false; }
    int box_r = r/3, box_c = c/3;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(arr[3*box_r+i][3*box_c+j]==x) return false;
        }
    }
    return true;
}

bool sudokuSolver(int arr[9][9]) {
    int r,c;
    if(done(arr, r, c)) return true;
    for(int x=1;x<=9;x++) {
        if(is_safe(arr,r,c,x)) {
            arr[r][c]=x;
            if(sudokuSolver(arr)) return true;
            arr[r][c]=0;
        }
    }
    return false;
}

