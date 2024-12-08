#include <stdio.h>
int main(){
	int arr[100];
	int n;
	int choice;
	int value;
	int found =0;
	int addindex;
	int index;
	int count=0;
	int first;
	int second;
	while(1){
		printf("\nMENU\n");
		printf("1. Nhap so luong va gia tri cac phan tu\n");
		printf("2. In mang (arr[0],...arr[n])\n ");
		printf("3. Dem so luong so hoan hao\n");
		printf("4. Dem so luong so nguyen to\n");
		printf("5. Tim gia tri lon thu hai\n");
		printf("6. Tim gia tri nho thu hai\n");
		printf("7. Them phan tu tai vi tri\n");
		printf("8. Xoa phan tu tai vi tri\n");
		printf("9. Sap xep mang tang dan\n");
		printf("10. Sap xep mang giam dan\n");
		printf("11. Tim kiem phan tu\n");
		printf("12. Xoa phan tu bi lap va in ra phan tu duy nhat\n");
		printf("13. Sap xep va hien thi so chan dung truoc so le dung sau\n");
		printf("14. Dao nguoc mang\n");
		printf("15. Thoat chuong trinh\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap so phan tu cua mang: ");
				scanf("%d", &n);
				while(n<=0){
					printf("Moi ban nhap lai so phan tu cua mang(>0): ");
					scanf("%d", &n);
				}
				printf("Moi ban nhap cac phan tu cua mang:\n ");
				for (int i=0; i<n;i++){
					printf("Phan tu %d ", i+1);
					scanf("%d", &arr[i]);
				}
				break;
			case 2:
				for(int i=0;i<n;i++){
					printf("Phan tu arr[%d] la %d \n", i, arr[i]);
				}
				break;
			case 3:
				for (int i =0; i<n;i++){
					int sum =0;
					for (int x=1;x<arr[i]; x++){
						sum+=x;
						if (sum == arr[i]){
							count++;
						}
					}
				}
				printf("Mang co %d so hoan hao ", count);
				break;
			case 4:
                {
				int countprime = 0;
                for (int i = 0; i < n; i++) {
                    int isprime = 1;
                    if (arr[i] < 2) {
                        isprime = 0;
                    }
                    for (int j = 2; j * j <= arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            isprime = 0;
                            break;
                        }
                    }
                    if (isprime) {
                        countprime++;
                    }
                }
                printf("So luong so nguyen to: %d\n", countprime);
            }
                break;
            case 5:
            	{
                int first = arr[0];
				int second = arr[1];
                if (first < second) {
                    first = arr[1];
                    second = arr[0];
                }
                for (int i = 2; i < n; i++) {
                    if (arr[i] > first) {
                        second = first;
                        first = arr[i];
                    } else if (arr[i] > second && arr[i] != first) {
                        second = arr[i];
                    }
                }
                printf("Gia tri lon thu hai: %d\n", second);
            }
                break;
            case 6:
            	{
                int min1 = arr[0];
				int min2 = arr[1];
                if (min1 > min2) {
                    min1 = arr[1];
                    min2 = arr[0];
                }
                for (int i = 2; i < n; i++) {
                    if (arr[i] < min1) {
                        min2 = min1;
                        min1 = arr[i];
                    } else if (arr[i] < min2 && arr[i] != min1) {
                        min2 = arr[i];
                    }
                }
                printf("Gia tri nho thu hai: %d\n", min2);
            }
                break;
            case 7:
            	{
                int position;
                printf("Nhap gia tri phan tu muon them: ");
                scanf("%d", &value);
                printf("Nhap vi tri muon them: ");
                scanf("%d", &position);
                if (position >= 0 && position <= n) {
                    for (int i = n; i > position; i--) {
                        arr[i] = arr[i-1];
                    }
                    arr[position] = value;
                    n++;
            } 	else {
                    printf("Vi tri khong hop le.\n");
                    }
                }
                break;
            case 8:
            	{
                int position;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &position);
                if (position >= 0 && position < n) {
                    for (int i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
            } 	else {
                    printf("Vi tri khong hop le.\n");
                    }
                }
                break;
            case 9:
                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep tang dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 10:
                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep giam dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 11:
            	{
                    int l = 0;
					int r = n - 1;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &value);
                    int found = 0;
                    while (l <= r) {
                        int mid = (l + r) / 2;
                        if (arr[mid] == value) {
                            found = 1;
                            printf("Phan tu %d duoc tim thay tai vi tri %d.\n", value, mid);
                            break;
                        } else if (arr[mid] < value) {
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                    if (!found) {
                        printf("Phan tu %d khong ton tai trong mang.\n", value);
                    }
                }
                break;
            case 12:
            	{
                    int unique[n];
					int uniquecount = 0;
                    for (int i = 0; i < n; i++) {
                        int isduplicate = 0;
                        for (int j = 0; j < uniquecount; j++) {
                            if (arr[i] == unique[j]) {
                                isduplicate = 1;
                                break;
                            }
                        }
                        if (!isduplicate) {
                            unique[uniquecount++] = arr[i];
                        }
                    }
                    printf("Cac phan tu duy nhat: ");
                    for (int i = 0; i < uniquecount; i++) {
                        printf("%d ", unique[i]);
                    }
                    printf("\n");
                }
                break;
            case 13:
            	{
                int even[n], odd[n];
                int evencount = 0;
				int oddcount = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        even[evencount++] = arr[i];
                    } else {
                        odd[oddcount++] = arr[i];
                    }
                }
                printf("Mang sau khi sap xep so chan dung truoc so le: ");
                for (int i = 0; i < evencount; i++) {
                    printf("%d ", even[i]);
                }
                for (int i = 0; i < oddcount; i++) {
                    printf("%d ", odd[i]);
                }
                printf("\n");
            }
                break;
            case 14:
                for (int i = 0; i < n / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
			case 15:
				return 0;
			default:
				printf("Lua chon khong hop le vui long chon lai!");		
		}
	}
	return 0;
}