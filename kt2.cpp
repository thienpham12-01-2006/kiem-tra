#include <stdio.h>
#include <string.h>

#define MAX 100 // Gioi han so thi sinh

// Cau truc de luu thong tin ve thi sinh
struct ThiSinh {
    int ma; // Ma thi sinh
    char ten[100]; // Ten thi sinh
    char ngaySinh[20]; // Ngay sinh
    int diem1, diem2, diem3; // Diem cac mon
    int tongDiem; // Tong diem
};

int main() {
    int n; // So luong thi sinh
    struct ThiSinh thiSinh[MAX];
    
    // Doc so luong thi sinh
    scanf("%d", &n);
    
    // Nhap thong tin cho tung thi sinh
    for (int i = 0; i < n; i++) {
        thiSinh[i].ma = i + 1; // Ma thi sinh bat dau tu 1
        
        // Nhap ten
        getchar(); // Doc ky tu xuong dong con lai
        fgets(thiSinh[i].ten, sizeof(thiSinh[i].ten), stdin);
        thiSinh[i].ten[strcspn(thiSinh[i].ten, "\n")] = '\0'; // Loai bo ky tu '\n' neu co
        
        // Nhap ngay sinh
        fgets(thiSinh[i].ngaySinh, sizeof(thiSinh[i].ngaySinh), stdin);
        thiSinh[i].ngaySinh[strcspn(thiSinh[i].ngaySinh, "\n")] = '\0'; // Loai bo ky tu '\n' neu co
        
        // Nhap diem cac mon
        scanf("%d %d %d", &thiSinh[i].diem1, &thiSinh[i].diem2, &thiSinh[i].diem3);
        
        // Tinh tong diem
        thiSinh[i].tongDiem = thiSinh[i].diem1 + thiSinh[i].diem2 + thiSinh[i].diem3;
    }
    
    // Tim thu khoa (thi sinh co tong diem cao nhat)
    int maxDiem = -1;
    for (int i = 0; i < n; i++) {
        if (thiSinh[i].tongDiem > maxDiem) {
            maxDiem = thiSinh[i].tongDiem;
        }
    }
    
    // In ra tat ca thi sinh co tong diem cao nhat
    for (int i = 0; i < n; i++) {
        if (thiSinh[i].tongDiem == maxDiem) {
            printf("%d %s %s %d\n", thiSinh[i].ma, thiSinh[i].ten, thiSinh[i].ngaySinh, thiSinh[i].tongDiem);
        }
    }
    
    return 0;
}
