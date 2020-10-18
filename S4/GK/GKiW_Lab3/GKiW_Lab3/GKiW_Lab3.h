// Deklaracje funkcji u¿ywanych jako obs³uga zdarzeñ GLUT-a.
void OnRender();
void OnReshape(int, int);
void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);
void OnSpecialKeyPress(int, int, int);
void OnSpecialKeyDown(int, int, int);
void OnSpecialKeyUp(int, int, int);
void OnTimer(int);

struct vec3 {
	float x, y, z;
};

struct SCameraState {
	vec3 pos;
	vec3 dir;
	float speed;
	float velM, velS; // zmienne pomocnicze do efektu bezwladnosci kamery - aktualna predkosc
};

SCameraState player;

double T = 0.0; // aktualny czas (a dokladniej - czas z ostatniego wywolania OnTimer())

vec3 LightPos; // pozycja zrodla swiatla

float val1 = -6.0, val2 = 0.0, val3 = -6.0, val4 = 0.0;
