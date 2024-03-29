﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Persona
    {
        private int edad;
        public string nombre;
        public string apellido;

        //constructor
        public Persona() { }

        //constructor con parametros
        public Persona(string nombre, string apellido,int edad)
        {
            this.nombre = nombre;
            this.apellido = apellido;
            this.edad = edad;     
        }

        public void setEdad(int edad)
        {
            this.edad = edad;
        }

        public int getEdad()
        {
            return this.edad;
        }

        public void cumplirAnios()
        {
           this.edad++;
        }
    }
}
