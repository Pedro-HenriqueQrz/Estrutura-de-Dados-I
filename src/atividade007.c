        #include <stdio.h>
        #include <locale.h>

        void ler_cenario(int n, int *cenario) {
            for (int i = 0; i < n; i++) {
                scanf("%d", cenario + i);
            }
        }

        int main() {
            setlocale(LC_ALL, "");
            int blocos;

            printf("Digite o numero de blocos no cenário: \n");
            scanf("%d", &blocos);

            int cenario[blocos];

            ler_cenario(blocos, cenario);

            for (int i = 0; i < blocos; i++) {
                if (*(cenario + i) == 1) {
                    *(cenario + i) = 2;
                    break;
                }
            }

            for (int i = 0; i < blocos; i++) {
                printf("%d ", *(cenario + i));
            }

            printf("\n");

            return 0;
        }