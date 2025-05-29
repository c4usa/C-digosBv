void mostrarMenu();
void agregarVehiculo(char nombres[][50], char cedulas[][15], char placas[][10], int estados[], int *cantidad);
void venderVehiculo(char nombres[][50], char cedulas[][15], char placas[][10], int estados[], int cantidad);
void buscarVehiculoPorCedula(char nombres[][50], char cedulas[][15], char placas[][10], int estados[], int cantidad);
int validarPlacaUnica(char placas[][10], int cantidad, char placa[]);
int validarCedulaUnica(char cedulas[][15], int cantidad, char cedula[]);
void mostrarVehiculo(char nombre[], char cedula[], char placa[], int estado, int indice);
void limpiarBuffer();