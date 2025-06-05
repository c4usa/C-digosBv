struct Materia
{
    char codigo[10];
    char nombre[20];
    float notas[3];
    float promedio;
};

struct Estudiante
{
    char codigo[10];
    char nombre[20];
    int edad;
    struct Materia materias[3];
    int numMaterias;

};
int menu();
void leerCadena(char *cadena, int num);
void crearMaterias(struct Materia materias[3], int cont);
void crearEstudiante(struct Estudiante estudiantes[3], int cont);
void imprimirMaterias(struct Materia materias[3], int cont);
void imprimirEstudiantes(struct Estudiante estudiantes[3], int cont);
