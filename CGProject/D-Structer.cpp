#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

struct snode {
	int info;
	struct snode *link;
};
typedef struct snode* SNODE;

struct dnode {
	int info;
	struct dnode *llink, *rlink;
};
typedef struct dnode *DNODE;

static SNODE sfirst = NULL;
static DNODE dfirst = NULL;
static int count = 0;
int inssucc = 0, delsucc = 0, succ = 1, p, q, info, key;

void drawstring(float x, float y, char *string) {
	char *c;
	glColor3f(0, 0, 0);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}

void drawstringsmall(float x, float y, char *string) {
	char *c;
	glColor3f(0, 0, 0);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
}

void buttonsStart() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);

	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(230, 300); glVertex2i(330, 300); glVertex2i(330, 350); glVertex2i(230, 350);
	glEnd();
	char insf[15] = "INSERT FRONT";
	drawstringsmall(235, 320, insf);

	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(230, 200); glVertex2i(330, 200); glVertex2i(330, 250); glVertex2i(230, 250);
	glEnd();
	char insr[15] = "INSERT REAR";
	drawstringsmall(235, 220, insr);

	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(230, 100); glVertex2i(330, 100); glVertex2i(330, 150); glVertex2i(230, 150);
	glEnd();
	char info[15] = "INFO";
	drawstringsmall(265, 120, info);
	glFlush();
}

void buttons() {
	glColor3f(0, 0, 1);
	glLineWidth(2);

	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 30); glVertex2i(110, 30); glVertex2i(110, 80); glVertex2i(10, 80);
	glEnd();
	char insf[15] = "INSERT FRONT";
	drawstringsmall(15, 50, insf);

	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(120, 30); glVertex2i(220, 30); glVertex2i(220, 80); glVertex2i(120, 80);
	glEnd();
	char insr[15] = "INSERT REAR";
	drawstringsmall(125, 50, insr);

	if (sfirst != NULL && dfirst != NULL) {
		glColor3f(0, 0, 1);
		glBegin(GL_LINE_LOOP);
		glVertex2i(230, 30); glVertex2i(330, 30); glVertex2i(330, 80); glVertex2i(230, 80);
		glEnd();
		char delf[15] = "DELETE FRONT";
		drawstringsmall(235, 50, delf);

		glColor3f(0, 0, 1);
		glBegin(GL_LINE_LOOP);
		glVertex2i(340, 30); glVertex2i(440, 30); glVertex2i(440, 80); glVertex2i(340, 80);
		glEnd();
		char delr[15] = "DELETE REAR";
		drawstringsmall(345, 50, delr);
	}
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(450, 30); glVertex2i(500, 30); glVertex2i(500, 80); glVertex2i(450, 80);
	glEnd();
	char info[15] = "INFO";
	drawstringsmall(455, 50, info);
	glFlush();
}

void back() {
	glColor3f(0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(470, 400); glVertex2i(570, 400); glVertex2i(570, 430); glVertex2i(470, 430);
	glEnd();
	char back[15] = "BACK";
	drawstringsmall(500, 410, back);
	glFlush();
}

void title() {
	glClear(GL_COLOR_BUFFER_BIT);
	char project_name[30] = "COMPUTER GRAPHICS PROJECT";
	drawstring(150, 450, project_name);
	char name[50] = "NAME: BHARGAVI N A AND GOUTHAMI S";
	drawstring(50, 350, name);
	char usn[35] = "USN: 1RN15CS035 AND 1RN15CS044";
	drawstring(50, 300, usn);
	char guided_by[12] = "GUIDED BY:";
	drawstring(50, 250, guided_by);
	char teach1[30] = "ASST. PROF. S MAMATHA JAJUR";
	drawstring(50, 200, teach1);
	char teach2[30] = "ASST. PROF. SAMPADA K S";
	drawstring(50, 150, teach2);
	char college[40] = "COLLEGE: RNS INSTITUTE OF TECHNOLOGY";
	drawstring(50, 100, college);
	back();
	glFlush();
}

void disp() {
	char a[20] = "Empty List";
	drawstring(250, 330, a);
	drawstring(250, 150, a);
	buttons();
	glFlush();
}

void sdisplay() {
	int j = 0, k = 0;
	SNODE temp;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	char a[20] = "SINGLY LINKED LIST";
	drawstring(50, 450, a);
	if (sfirst == NULL) {
		printf("List is empty\n");
		disp();	//Displays Empty List
		return;
	}
	printf("The contents of the singly linked list are:\n");
	temp = sfirst;
	while (temp != NULL) {
		for (k = 0; k < count; k++) {
			int x1 = 50, x2 = 80, x3 = 110, x4 = 95, x5 = 160, x6 = 180;
			int y1 = 350, y2 = 375, y3 = 400, y4 = 375, y5 = 360, y6 = 390;
			glLineWidth(2);
			if (sfirst->link == NULL) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);
				glVertex2i(x2 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
			}
			if (temp->link == NULL) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//InfoBlock
				glVertex2i(x1 + k * 130, y1); glVertex2i(x1 + k * 130, y3);
				glVertex2i(x2 + k * 130, y3); glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//LinkBlock
				glVertex2i(x2 + k * 130, y1); glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//NullLine
				glVertex2i(x2 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
			}
			else {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//ArrowLine
				glVertex2i(x4 + k * 130, y4); glVertex2i(x6 + k * 130, y4);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//ArrowHead
				glVertex2i(x5 + k * 130, y6); glVertex2i(x6 + k * 130, y4);
				glVertex2i(x6 + k * 130, y4); glVertex2i(x5 + k * 130, y5);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//InfoBlock
				glVertex2i(x1 + k * 130, y1); glVertex2i(x1 + k * 130, y3);
				glVertex2i(x2 + k * 130, y3); glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//LinkBlock
				glVertex2i(x2 + k * 130, y1); glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
			}
			int x = temp->info;
			printf("%d", temp->info);
			temp = temp->link;
			printf("\n");
			p = x / 10;
			q = x % 10;
			p = p + 48;
			q = q + 48;
			glColor3f(0, 0, 1);	//Changes the color of the number
			glRasterPos2f(55 + k * 130, 370);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, p);	//Display Numbers
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, q);
			char info[5] = "INFO";
			drawstringsmall(50 + k * 130, 330, info);
			char link[5] = "LINK";
			drawstringsmall(85 + k * 130, 330, link);
			j++;
			glFlush();
		}
	}
}

void ddisplay() {
	int j = 0, k = 0;
	DNODE temp;
	char a[20] = "DOUBLY LINKED LIST";
	drawstring(50, 250, a);
	if (dfirst == NULL) {
		printf("List is empty.\n");
		disp();	//Displays Empty List
		return;
	}
	printf("The contents of the doubly linked list are:\n");
	temp = dfirst;
	while (temp != NULL) {
		for (k = 0; k < count; k++) {
			glColor3f(0, 0, 0);
			glLineWidth(2);
			int x1 = 50, x2 = 80, x3 = 110, x4 = 140, x5 = 125, x6 = 180, x7 = 160;
			int y1 = 150, y2 = 175, y3 = 200, y4 = 175, y5 = 160, y6 = 190;
			if (dfirst->rlink == NULL && dfirst->llink == NULL) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//llinkNulllLine
				glVertex2i(x1 + k * 130, y3); glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//rlinkNullLine
				glVertex2i(x3 + k * 130, y3); glVertex2i(x4 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//llinkBlock
				glVertex2i(x1 + k / 2 * 130, y1); glVertex2i(x1 + k / 2 * 130, y3);
				glVertex2i(x2 + k / 2 * 130, y3); glVertex2i(x2 + k / 2 * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//InfoBlock
				glVertex2i(x2 + k * 130, y1); glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//rlinkBlock
				glVertex2i(x3 + k / 2 * 130, y1); glVertex2i(x3 + k / 2 * 130, y3);
				glVertex2i(x4 + k / 2 * 130, y3); glVertex2i(x4 + k / 2 * 130, y1);
				glEnd();
			}
			else if (temp->llink != NULL && temp->rlink == NULL) {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//FirstNode llink Null Line
				glVertex2i(x1, y3); glVertex2i(x2, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//llink Block
				glVertex2i(x1 + k * 130, y1); glVertex2i(x1 + k * 130, y3);
				glVertex2i(x2 + k * 130, y3); glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//Info Block
				glVertex2i(x2 + k * 130, y1); glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//rlink Block
				glVertex2i(x3 + k * 130, y1); glVertex2i(x3 + k * 130, y3);
				glVertex2i(x4 + k * 130, y3); glVertex2i(x4 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);	//rlink Null Line
				glVertex2i(x3 + k * 130, y3); glVertex2i(x4 + k * 130, y1);
				glEnd();
			}
			else {
				glColor3f(0, 0, 0);
				glBegin(GL_LINES); //ArrowLine
				glVertex2i(x5 + k * 130, y4); glVertex2i(x6 + k * 130, y4);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINES); //ArrowHead
				glVertex2i(x6 + k * 130, y4); glVertex2i(x7 + k * 130, y6);
				glVertex2i(x6 + k * 130, y4); glVertex2i(x7 + k * 130, y5);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP); //llink Block
				glVertex2i(x1 + k * 130, y1); glVertex2i(x1 + k * 130, y3);
				glVertex2i(x2 + k * 130, y3); glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//Info Block
				glVertex2i(x2 + k * 130, y1); glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3); glVertex2i(x3 + k * 130, y1);
				glEnd();
				glColor3f(0, 0, 0);
				glBegin(GL_LINE_LOOP);	//rlink Block
				glVertex2i(x3 + k * 130, y1); glVertex2i(x3 + k * 130, y3);
				glVertex2i(x4 + k * 130, y3); glVertex2i(x4 + k * 130, y1);
				glEnd();
			}
			int x = temp->info;
			printf("%d", temp->info);
			temp = temp->rlink;
			printf("\n");
			p = x / 10; q = x % 10;
			p = p + 48; q = q + 48;
			glColor3f(0, 0, 1);
			glRasterPos2f(85 + k * 130, 170);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, p);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, q);
			char link[6] = "LINK";
			drawstringsmall(50 + k * 130, 135, link);
			char info[5] = "INFO";
			drawstringsmall(85 + k * 130, 135, info);
			drawstringsmall(115 + k * 130, 135, link);
			j++;
			glFlush();
		}
	}
	buttons();
}

void display() {
	sdisplay();
	ddisplay();
	glFlush();
}

void renderscene() {
	if (sfirst != NULL)
		display();
	else
		buttonsStart();
}

void displayinit() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	if (h > 480)
		glutReshapeWindow(w, 480);
	glutPostRedisplay();
}

void getnode() {
	printf("Enter element to be inserted: ");
	scanf_s("%d", &info);
	int digitcount = 0;
	int num = info;
	while (num != 0) {
		num /= 10;
		digitcount++;
		if (digitcount >= 3) {
			printf("Enter only two-digit numbers.\n");
			printf("Enter element to be inserted: ");
			scanf_s("%d", &info);
			num = info;
			digitcount = 0;
		}
	}
}

SNODE sgetnode() {
	SNODE temp;
	temp = (SNODE)malloc(sizeof(struct snode));
	if (temp == NULL) {
		printf("Memory not allocated\n");
		exit(0);
	}
	temp->info = info;
	temp->link = NULL;
	return temp;
}

SNODE sinsertfront(SNODE sfirst) {
	SNODE temp = sgetnode();
	if (sfirst == NULL)
		return temp;
	else {
		temp->link = sfirst;
		return temp;
	}
}

SNODE sinsertrear(SNODE sfirst) {
	SNODE temp = sgetnode(), curr;
	if (sfirst == NULL)
		return temp;
	else {
		for (curr = sfirst; curr->link != NULL; curr = curr->link);
		curr->link = temp;
		return sfirst;
	}
}

SNODE sinsertspecified(SNODE first) {
	SNODE next, cur, temp = sgetnode();
	temp->info = info;
	if (sfirst == NULL) {
		temp->link = NULL;
		sfirst = temp;
		return sfirst;
	}
	printf("Enter the key node after which the element must be inserted: ");
	scanf_s("%d", &key);
	cur = sfirst;
	while (cur != NULL) {
		next = cur->link;
		if (cur->info == key) {
			inssucc = 1;
			cur->link = temp;
			temp->link = next;
			return sfirst;
		}
		cur = cur->link;
	}
	if (cur == NULL) {
		printf("SLL: Key not found.\n");
		count--;
	}
	return sfirst;
}

SNODE sdeletefront(SNODE sfirst) {
	SNODE temp = sfirst;
	if (sfirst == NULL) {
		printf("SLL: List empty.\n");
		return sfirst;
	}
	else if (sfirst->link == NULL) {
		printf("SLL: Element deleted is %d.\n", sfirst->info);
		free(sfirst);
		return NULL;
	}
	else {
		printf("SLL: Element deleted is %d.\n", sfirst->info);
		sfirst = sfirst->link;
		free(temp);
		return sfirst;
	}
}

SNODE sdeleterear(SNODE sfirst) {
	SNODE curr, prev = NULL;
	if (sfirst == NULL) {
		printf("SLL: List empty.\n");
		return sfirst;
	}
	else if (sfirst->link == NULL) {
		printf("SLL: Element deleted is %d.\n", sfirst->info);
		free(sfirst);
		return NULL;
	}
	else {
		for (curr = sfirst; curr->link; curr = curr->link)
			prev = curr;
		printf("SLL: Element deleted is %d.\n", curr->info);
		free(curr);
		prev->link = NULL;
		return sfirst;
	}
}

SNODE sdeletespecified(SNODE sfirst) {
	SNODE prev, cur;
	if (sfirst == NULL) {
		disp();
		count++;
		return NULL;
	}
	printf("Enter the key: ");
	scanf_s("%d", &key);
	if (key == sfirst->info) {
		delsucc = 1;
		cur = sfirst;
		sfirst = sfirst->link;
		printf("SLL: The element deleted is %d\n", cur->info);
		free(cur);
		delsucc = 1;
		return sfirst;
	}
	prev = NULL;
	cur = sfirst;
	while (cur != NULL) {
		if (key == cur->info) {
			delsucc = 1;
			break;
		}
		prev = cur;
		cur = cur->link;
	}
	if (cur == NULL) {
		printf("SLL: Key not found.\n");
		count++;
		return sfirst;
	}
	prev->link = cur->link;
	printf("SLL: The element deleted is %d\n", cur->info);
	free(cur);
	return sfirst;
}

DNODE dgetnode() {
	DNODE temp = (DNODE)malloc(sizeof(struct dnode));
	if (temp == NULL) {
		printf("Memory not allocated\n");
		exit(0);
	}
	temp->info = info;
	temp->llink = temp->rlink = NULL;
	return temp;
}

DNODE dinsertfront(DNODE dfirst) {
	DNODE temp = dgetnode();
	if (dfirst == NULL)
		return temp;
	else {
		temp->rlink = dfirst;
		dfirst->llink = temp;
		return temp;
	}
}

DNODE dinsertrear(DNODE dfirst) {
	DNODE temp = dgetnode(), curr;
	if (dfirst == NULL)
		return temp;
	curr = dfirst;
	while (curr->rlink != NULL)
		curr = curr->rlink;
	curr->rlink = temp;
	temp->llink = curr;
	return dfirst;
}

DNODE dinsertspecified(DNODE dfirst) {
	DNODE temp = dgetnode(), curr = dfirst;
	temp->info = info;
	if (dfirst == NULL)
		return temp;
	while (curr != NULL) {
		if (curr->info == key) {
			temp->rlink = curr->rlink;
			curr->rlink = temp;
			temp->llink = curr;
			return dfirst;
		}
		curr = curr->rlink;
	}
	if (curr == NULL) {
		printf("DLL: Key not found.\n");
		return dfirst;
	}
}

DNODE ddeletefront(DNODE dfirst) {
	DNODE temp = dfirst;
	if (dfirst == NULL) {
		printf("DLL: List empty.\n");
		return dfirst;
	}
	else if (dfirst->rlink == NULL) {
		printf("DLL: The element deleted is %d.\n", dfirst->info);
		free(dfirst);
		return NULL;
	}
	else {
		dfirst = dfirst->rlink;
		dfirst->llink = NULL;
		printf("DLL: The element deleted is %d.\n", temp->info);
		free(temp);
		return dfirst;
	}
}

DNODE ddeleterear(DNODE dfirst) {
	DNODE prev = NULL, curr;
	if (dfirst == NULL) {
		printf("DLL: List empty.\n");
		return dfirst;
	}
	else if (dfirst->rlink == NULL) {
		printf("DLL: The element deleted is %d.\n", dfirst->info);
		free(dfirst);
		return NULL;
	}
	else {
		for (curr = dfirst; curr->rlink; curr = curr->rlink)
			prev = curr;
		printf("DLL: The element deleted is %d.\n", curr->info);
		free(curr);
		prev->rlink = NULL;
		return dfirst;
	}
}

DNODE ddeletespecfied(DNODE dfirst) {
	if (dfirst == NULL) {
		disp();
		return dfirst;
	}
	DNODE curr = dfirst, prev = NULL, delnode;
	if (dfirst->info == key) {
		curr = dfirst;
		dfirst = dfirst->rlink;
		if (dfirst != NULL)
			dfirst->llink = NULL;
		printf("DLL: The element deleted is %d.\n", curr->info);
		free(curr);
		return dfirst;
	}
	prev = NULL;
	curr = dfirst;
	while (curr != NULL) {
		if (key == curr->info)
			break;
		prev = curr;
		curr = curr->rlink;
	}
	if (curr == NULL) {
		printf("DLL: Key not found.\n");
		return dfirst;
	}
	prev->rlink = curr->rlink;
	delnode = curr;
	curr = curr->rlink;
	if (curr != NULL)
		curr->llink = prev;
	printf("DLL: The element deleted is %d.\n", delnode->info);
	free(delnode);
	return dfirst;
}

void menu(int choice) {
	switch (choice) {
	case 1: {
		getnode();
		sfirst = sinsertspecified(sfirst); dfirst = dinsertspecified(dfirst);
		count++;
		if (inssucc == 1)
			display();
		break;
	}
	case 2: {
		sfirst = sdeletespecified(sfirst);
		dfirst = ddeletespecfied(dfirst);
		count--;
		if (delsucc == 1)
			display();
		break;
	}
	case 3:
		title();
		break;
	case 4:
		exit(0);
	}
}

void mouse(int b, int s, int x, int y) {
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN) {
		if (x >= 10 && x <= 110 && y >= 400 && y <= 450) {
			getnode();
			sfirst = sinsertfront(sfirst); dfirst = dinsertfront(dfirst);
			count++;
			display();
		}
		if (x >= 120 && x <= 220 && y >= 400 && y <= 450) {
			getnode();
			sfirst = sinsertrear(sfirst); dfirst = dinsertrear(dfirst);
			count++;
			display();
		}
		if (sfirst != NULL && dfirst != NULL) {
			if (x >= 230 && x <= 330 && y >= 400 && y <= 450) {
				sfirst = sdeletefront(sfirst); dfirst = ddeletefront(dfirst);
				count--;
				display();
			}
			if (x >= 340 && x <= 440 && y >= 400 && y <= 450) {
				sfirst = sdeleterear(sfirst); dfirst = ddeleterear(dfirst);
				count--;
				display();
			}
		}
		if (x >= 450 && x <= 500 && y >= 400 && y <= 450)
			title();
		if (x >= 230 && x <= 330 && y >= 125 && y <= 175) {
			getnode();
			sfirst = sinsertfront(sfirst); dfirst = dinsertfront(dfirst);
			count++;
			display();
		}
		if (x >= 230 && x <= 330 && y >= 225 && y <= 275) {
			getnode();
			sfirst = sinsertrear(sfirst); dfirst = dinsertrear(dfirst);
			count++;
			display();
		}
		if (x >= 230 && x <= 330 && y >= 325 && y <= 375)
			title();
		if (x >= 470 && x <= 570 && y >= 60 && y <= 80) {
			if (sfirst != NULL && dfirst != NULL)
				display();
			else
				buttonsStart();
		}
	}
}

int main() {
	printf("LINKED LISTS\n\n");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 480);
	glutInitWindowPosition(650, 40);
	glutCreateWindow("LINKED LISTS");
	glutCreateMenu(menu);
	glutAddMenuEntry("Insert Specfied", 1);
	glutAddMenuEntry("Delete Specified", 2);
	glutAddMenuEntry("Project Information", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(renderscene);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	displayinit();
	glutMainLoop();
}