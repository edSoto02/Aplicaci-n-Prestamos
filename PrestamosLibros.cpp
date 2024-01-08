#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define true 1
#define false 0
#define bool int

typedef struct 
{
	char clave_libro[40];
	char nombreLibro[40];
	char autor[40];
	char dia_de_prestamo[20];
	char persona[40];
	int persona_edad;
	char persona_direccion[70];
	int persona_telefono;
	
}prestamos;

FILE *archivo_1, *temporal;


void menu(){
	printf("Registra Prestamos\n");
	printf("Que desea hacer?\n");
	printf("\n1) Registrar un Prestamos");
	printf("\n2) Consultar datos de un Prestamo");
	printf("\n3) Modifica datos de un Prestamo");
	printf("\n4) Eliminar Prestamo");
	printf("\n5) Salir(S/N)\n\n");
}
//Agrega un equipo
void Agregar_Prestamo(prestamos p[]){
	int z,i, comparacion;
	char respuesta, compara[20];
	bool no_encontrado;
		i=0;
		do{
			if ((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
				printf("No se pudo localizar el archivo\n\n");
				printf("Desea salir al menu? (S/N): ");
				respuesta = getch();
			}else{
				system("cls");
				no_encontrado=true;
				printf("Introdusca Clave del libro (Ejemplo:001): ");
				fflush(stdin);
				scanf("%s",&compara);
					
				z=0;	
				do{
					
					fflush(stdin);
					fscanf(archivo_1, "%s", &p[z].clave_libro);
					comparacion=strcmp(compara,p[z].clave_libro);
					if(comparacion==0){
					no_encontrado=false;
					}	
				
				z++;
				}while((!feof(archivo_1)) && (no_encontrado));
				fclose(archivo_1);
					
					if(no_encontrado){
						archivo_1=fopen("PrestamosUACM.txt","a");
					
							system("cls");
							
							printf("Introdusca Nuevamente la Clave del libro (Ejemplo:001): ");
							fflush(stdin);
							scanf("%s", &p[i].clave_libro);
							printf("\nIngresa Nombre del Libro: ");
							fflush(stdin);
							scanf("%s", &p[i].nombreLibro);//quiero dejar espacios entre cada caracter
							printf("\nIngresa Autor: ");
							fflush(stdin);
							scanf("%s", &p[i].autor);
							printf("\nIngresa el Dia de Prestamo: ");
							fflush(stdin);
							scanf("%s", &p[i].dia_de_prestamo);
							printf("\nIngresa Nombre de la Persona a la que se le Presta el Libro: ");
							fflush(stdin);
							scanf("%s", &p[i].persona);//quiero dejar espacios entre cada caracter
							printf("\nIngresa Edad de la Persona: ");
							fflush(stdin);
							scanf("%d", &p[i].persona_edad);
							printf("\nIngresa Direccion de la Persona: ");
							fflush(stdin);
							scanf("%s", &p[i].persona_direccion);
							printf("\nIngresa Telefono de la Persona: ");
							fflush(stdin);
							scanf("%d", &p[i].persona_telefono);
							
							fprintf(archivo_1,"%s %s %s %s %s %d %s %d \n", p[i].clave_libro, p[i].nombreLibro,
                                    p[i].autor, p[i].dia_de_prestamo, p[i].persona, p[i].persona_edad,
                                    p[i].persona_direccion, p[i].persona_telefono);
							i++;
							printf("Desea Registrar otro Prestamo(S/N): \n");
							respuesta = getch();
						
						fclose(archivo_1);	
					}else{
						printf("Este Prestamo ya fue realizado\n\n");
						printf("Desea Registrar otro Prestamo(S/N): \n");
						respuesta = getch();
					}	
			}	
		}while((respuesta == 's' || respuesta == 'S'));
		
}

void Eliminar_Un_Prestamo(prestamos p[]){
	char respuesta_0, respuesta_seguro;
	bool salir = false;
	int z,i,t=1, comparacion;
	char respuesta, compara[20], modificar, cedula_temp[20];
	bool no_encontrado;

	do{
		system("cls");
		printf("Que deseas eliminar:\n");
        printf("\n1) Eliminar todos los Prestamo:");
        printf("\n2) Eliminar un Prestamo:");
        printf("\n3) Salir al menu principal(S/N):");
        printf("\nSelecione una opcion: ");
        respuesta_0 = getch();
		switch(respuesta_0){
			case '1':
				do{
					system("cls");	
					if((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
					printf("No se pudo localizar el archivo\n\n");
					printf("Desea salir al menu? (S/N): ");
					respuesta = getch();
					}else{
					
						printf("\n\nSeguro deseas eliminar todos los datos (S/N): ");
					    respuesta_seguro = getch();
						if ((respuesta_seguro == 's') || (respuesta_seguro == 'S'))
						{
							if((archivo_1 = fopen("PrestamosUACM.txt","w")) == NULL)
							{
								printf ("\n No se Encuentra el Archivo!");
								printf("\nDesea salir al menu? (S/N): ");
								respuesta = getch();
							}else{
								fclose(archivo_1);
								printf ("\nSe vacio el registro");
								
							}
						}
						
		   			}
		   				printf("\n\nDesea volver al menu(S/N): ");
						respuesta = getch();
				}while((respuesta == 'n' || respuesta == 'N'));
			break;	
			
			case '2':
				do{
					system("cls");
					if((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
					printf("No se pudo localizar el archivo\n\n");
					printf("Desea salir al menu? (S/N): ");
					respuesta = getch();
					}else{
						
						system("cls");
						no_encontrado=true;
						printf("Introdusca la Clave del libro (Ejemplo:001) Para eliminar ese prestamo: ");
						fflush(stdin);
						scanf("%s",&compara);
						z=0;	
						do{
							fflush(stdin);
							fscanf(archivo_1, "%s", &p[z].clave_libro);
							comparacion=strcmp(compara,p[z].clave_libro);
							if(comparacion==0){	
							no_encontrado=false;
							}	
						z++;
						}while((!feof(archivo_1)) && (no_encontrado));
							if(no_encontrado){
								fclose(archivo_1);
								printf("No encontre esta Clave por lo tanto el libro no esta prestado o no registro prestamo\n\n");
							
							}else{
								
								printf("Registro del Prestamo /%s/ Encontrado. \n", p[z].clave_libro); //duda
								fclose(archivo_1);
								printf ("\n Desea Eliminar este Prestamo? S/N: ");
		               			modificar = getch();
		               			}
		               			if ((modificar == 's') || (modificar == 'S')){
		               				
		               				if ((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
										printf("No se pudo localizar el archivo\n\n");
										printf("Desea salir al menu? (S/N): ");
										respuesta = getch();
										}else{
											temporal = fopen("temporal.txt","w");
											i=0;
											while(!feof(archivo_1)){
											fscanf(archivo_1,"%s %s %s %s %s %d %s %d \n",
                                                   &p[i].clave_libro, &p[i].nombreLibro, &p[i].autor,
                                                   &p[i].dia_de_prestamo, &p[i].persona, &p[i].persona_edad,
                                                   &p[i].persona_direccion, &p[i].persona_telefono);
											comparacion=strcmp(compara,p[i].clave_libro);
												if(comparacion!=0){
													fprintf(temporal,"%s %s %s %s %s %d %s %d \n",
                                                            p[i].clave_libro, p[i].nombreLibro, p[i].autor,
                                                            p[i].dia_de_prestamo, p[i].persona, p[i].persona_edad,
                                                            p[i].persona_direccion, p[i].persona_telefono);
												}
											i++;	
											}
											fclose(temporal);
											fclose(archivo_1);
												if ((temporal = fopen("temporal.txt","r")) == NULL){
												printf("No se pudo localizar el archivo\n\n");
												printf("Desea salir al menu? (S/N): ");
												respuesta = getch();
												}else{
													archivo_1 = fopen("PrestamosUACM.txt","w");
													i=0;
													while(!feof(temporal)){
														fscanf(temporal,"%s %s %s %s %s %d %s %d \n",
                                                               &p[i].clave_libro, &p[i].nombreLibro, &p[i].autor,
                                                               &p[i].dia_de_prestamo, &p[i].persona, &p[i].persona_edad,
                                                               &p[i].persona_direccion, &p[i].persona_telefono);
														fprintf(archivo_1,"%s %s %s %s %s %d %s %d \n",
                                                                p[i].clave_libro, p[i].nombreLibro, p[i].autor,
                                                                p[i].dia_de_prestamo, p[i].persona, p[i].persona_edad,
                                                                p[i].persona_direccion, p[i].persona_telefono);
													}
													fclose(temporal);
													fclose(archivo_1);
													printf ("\n\n Se ha Modificado el Registro");
													temporal = fopen("temporal.txt","w");
													fclose(temporal);
													
												}
								  		}		
								}	
					printf("\n\nDesea eliminar otro prestamo(S/N): ");
					respuesta = getch();			
						
					}	
					
				}while((respuesta == 's' || respuesta == 'S'));		
			break;
			
			case's': case 'S':
				salir = true;
				break;	
		}
		
   }while(salir == false);
}

//consulta equipo 
void Consultar_Prestamo(prestamos p[]){
	int i, z, comparacion;
	char respuesta, respuesta_0, compara[20];
	bool salir = false;
	bool no_encontrado;
	do{
		system("cls");
		printf("Que deseas que te muestre:\n");
        printf("\n1) Mostrar todos los prestamos\n");
        printf("\n2) Mostrar solo un prestamo en especifico\n");
        printf("\n3) Salir al menu principal(S/N)\n");
        printf("\nSelecione una opcion: ");
        respuesta_0 = getch();
		switch(respuesta_0){
			case '1':
				do{
					system("cls");	
					if((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
					printf("No se pudo localizar el archivo\n\n");
					printf("Desea salir al menu? (S/N): ");
					respuesta = getch();
					}else{
						
						system("cls");
						i=0;
						while(!feof(archivo_1)){
						fscanf(archivo_1,"%s %s %s %s %s %d %s %d \n",
                               &p[i].clave_libro, &p[i].nombreLibro, &p[i].autor,
                               &p[i].dia_de_prestamo, &p[i].persona, &p[i].persona_edad,
                               &p[i].persona_direccion, &p[i].persona_telefono);
						printf("\nClave del Libro: %s \nNombre del Libro: %s \nNombre del Autor: %s \nDia de prestamo: %s \nPersona a la que se le Presto: %s \nEdad de la Persona: %d \nDireccion de la Persona: %s \nTelefono de la Persona: %d\n"
                               ,p[i].clave_libro, p[i].nombreLibro, p[i].autor, p[i].dia_de_prestamo,
                               p[i].persona, p[i].persona_edad, p[i].persona_direccion, p[i].persona_telefono);
						i++;
			   			}
						fclose(archivo_1);
		   			}
		   				printf("\n\nDesea volver al menu(S/N): ");
						respuesta = getch();
				}while((respuesta == 'n' || respuesta == 'N'));
			break;	
			
			case '2':
				do{
					system("cls");
					if((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
					printf("No se pudo localizar el archivo\n\n");
					printf("Desea salir al menu? (S/N): ");
					respuesta = getch();
					}else{
						system("cls");
						no_encontrado=true;
						printf("Introdusca Clave del libro (Ejemplo:001): ");
							scanf("%s",&compara);
						
							z=0;	
							do{	
								fscanf(archivo_1,"%s %s %s %s %s %d %s %d \n",
                                       &p[z].clave_libro, &p[z].nombreLibro, &p[z].autor, &p[z].dia_de_prestamo,
                                       &p[z].persona, &p[z].persona_edad, &p[z].persona_direccion,
                                       &p[z].persona_telefono);
								comparacion=strcmp(compara,p[z].clave_libro);
								if(comparacion==0){
									printf("\nClave del Libro: %s \nNombre del Libro: %s \nNombre del Autor: %s \nDia de prestamo: %s \nPersona a la que se le Presto: %s \nEdad de la Persona: %d \nDireccion de la Persona: %s \nTelefono de la Persona: %d\n",
                                           p[z].clave_libro, p[z].nombreLibro, p[z].autor, p[z].dia_de_prestamo,
                                           p[z].persona, p[z].persona_edad, p[z].persona_direccion,
                                           p[z].persona_telefono);
									no_encontrado=false;
								}
								if((comparacion<0 || comparacion>0) && feof(archivo_1) && no_encontrado){
									printf("\nNo se encontro la clave del libro.");
								}
							z++;
							}while(!feof(archivo_1));
					}	
					printf("\n\nDesea buscar los datos de otro prestamo(S/N): ");
					respuesta = getch();
				}while((respuesta == 's' || respuesta == 'S'));		
			break;
			
			case's': case 'S':
				salir = true;
				break;	
		}
		
   }while(salir == false);
}
//modifica equipo
void Modificar_Datos_De_Un_Prestamo(prestamos p[]){
	int z,i,t=1, comparacion;
	char respuesta, compara[20], modificar, cedula_temp[20];
	bool no_encontrado;
		i=0;
		do{
			if ((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
				printf("No se pudo localizar el archivo\n\n");
				printf("Desea salir al menu? (S/N): ");
				respuesta = getch();
			}else{
				system("cls");
				no_encontrado=true;
				printf("Introdusca la Clave del libro (Ejemplo:001): ");
				fflush(stdin);
				scanf("%s",&compara);
				z=0;	
				do{
					fflush(stdin);
					fscanf(archivo_1, "%s", &p[z].clave_libro);
					comparacion=strcmp(compara,p[z].clave_libro);
					if(comparacion==0){	
					no_encontrado=false;
					}	
				z++;
				}while((!feof(archivo_1)) && (no_encontrado));
					if(no_encontrado){
						fclose(archivo_1);
						printf("No encontre esta Clave por lo tanto el libro no esta prestado o no registro prestamo\n\n");
						printf("Desea Modificar otro Prestamo(S/N): \n");
						respuesta = getch();
						
					}else{
						
						printf("Registro del Prestamo /%s/ Encontrado. \n", p[z].clave_libro); //duda
						fclose(archivo_1);
						printf ("\nDesea Modificar este Prestamo? S/N: ");
               			modificar = getch();
               			}
               			if ((modificar == 's') || (modificar == 'S')){
               				
               				if ((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
								printf("No se pudo localizar el archivo\n\n");
								printf("Desea salir al menu? (S/N): ");
								respuesta = getch();
								}else{
									temporal = fopen("temporal.txt","w");
									i=0;
									while(!feof(archivo_1)){
									fscanf(archivo_1,"%s %s %s %s %s %d %s %d \n",
                                           &p[i].clave_libro, &p[i].nombreLibro, &p[i].autor, &p[i].dia_de_prestamo,
                                           &p[i].persona, &p[i].persona_edad, &p[i].persona_direccion,
                                           &p[i].persona_telefono);
									comparacion=strcmp(compara,p[i].clave_libro);
										if(comparacion!=0){
											fprintf(temporal,"%s %s %s %s %s %d %s %d \n",
                                                    p[i].clave_libro, p[i].nombreLibro, p[i].autor,
                                                    p[i].dia_de_prestamo, p[i].persona, p[i].persona_edad,
                                                    p[i].persona_direccion, p[i].persona_telefono);
										}else{
											printf("\nEstamos modificando los datos, pero necesito que ingrese los nuevos datos.\n");
											printf("Ingresa Datos:\n\n");
											printf("Introdusca Clave del libro (Ejemplo:001): ");
											fflush(stdin);
											scanf("%s", &p[i].clave_libro);
											printf("\nIngresa Nombre del Libro: ");
											fflush(stdin);
											scanf("%s", &p[i].nombreLibro);//quiero dejar espacios entre cada caracter
											printf("\nIngresa Autor: ");
											fflush(stdin);
											scanf("%s", &p[i].autor);
											printf("\nIngresa el Dia de Prestamo: ");
											fflush(stdin);
											scanf("%s", &p[i].dia_de_prestamo);
											printf("\nIngresa Nombre de la Persona a la que se le Presta el Libro: ");
											fflush(stdin);
											scanf("%s", &p[i].persona);//quiero dejar espacios entre cada caracter
											printf("\nIngresa Edad de la Persona: ");
											fflush(stdin);
											scanf("%d", &p[i].persona_edad);
											printf("\nIngresa Direccion de la Persona: ");
											fflush(stdin);
											scanf("%s", &p[i].persona_direccion);
											printf("\nIngresa Telefono de la Persona: ");
											fflush(stdin);
											scanf("%d", &p[i].persona_telefono);
											fprintf(temporal,"%s %s %s %s %s %d %s %d \n",
                                                    p[i].clave_libro, p[i].nombreLibro, p[i].autor,
                                                    p[i].dia_de_prestamo, p[i].persona, p[i].persona_edad,
                                                    p[i].persona_direccion, p[i].persona_telefono);
										}
									i++;	
									}
									fclose(temporal);
									fclose(archivo_1);
										if ((temporal = fopen("temporal.txt","r")) == NULL){
										printf("No se pudo localizar el archivo\n\n");
										printf("Desea salir al menu? (S/N): ");
										respuesta = getch();
										}else{
											archivo_1 = fopen("PrestamosUACM.txt","w");
											i=0;
											while(!feof(temporal)){
												fscanf(temporal,"%s %s %s %s %s %d %s %d \n",
                                                       &p[i].clave_libro, &p[i].nombreLibro, &p[i].autor,
                                                       &p[i].dia_de_prestamo, &p[i].persona, &p[i].persona_edad,
                                                       &p[i].persona_direccion, &p[i].persona_telefono);
												fprintf(archivo_1,"%s %s %s %s %s %d %s %d \n",
                                                        p[i].clave_libro, p[i].nombreLibro, p[i].autor,
                                                        p[i].dia_de_prestamo, p[i].persona, p[i].persona_edad,
                                                        p[i].persona_direccion, p[i].persona_telefono);
											}
											fclose(temporal);
											fclose(archivo_1);
											printf ("\n\n Se ha Modificado el Registro");
											temporal = fopen("temporal.txt","w");
											fclose(temporal);
											printf("\nDesea Modificar otro Prestamo(S/N): \n");
											respuesta = getch();
										}
						  		}		
						}	
						
			}
		}while((respuesta == 's' || respuesta == 'S'));
}


int main(){
	prestamos p[50];
	
	char opcion;
	bool salir = false;
		do{
		system("cls");
		if((archivo_1 = fopen("PrestamosUACM.txt","r")) == NULL){
			printf("El programa se esta ejecutando por primera vez\n\n");
			archivo_1 = fopen("PrestamosUACM.txt","w");
			fclose(archivo_1);
			/*archivo_2 = fopen("adopciones.dat","w");
			fclose(archivo_2);*/
			printf("Archivo creado\n\n");
			menu();
			printf("Elije una opcion: ");
			opcion = getche();
		}else{
			menu();
			printf("Elije una opcion: ");
			opcion = getche();			
			}		
		switch(opcion){
			case '1':
				Agregar_Prestamo(p);
			break;
			
			case '2':
				Consultar_Prestamo(p);
			break;
			
			case '3':
				Modificar_Datos_De_Un_Prestamo(p);
			break;	
			
			case '4':
				Eliminar_Un_Prestamo(p);
			break;	
			
			case's': case 'S':
				salir = true;
				break;
		}
	}while(salir == false);
}
