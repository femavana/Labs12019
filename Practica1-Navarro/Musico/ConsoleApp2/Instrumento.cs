using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Instrumento
    {
        public string nombre;
        public TipoInstrumento tipo;

        // como define dentro o fuera de la class es igual
        public enum TipoInstrumento { Guitarra, Flauta }

        //constructor
        public Instrumento() { }

        //constructor con parametros
        public Instrumento(string nombre, TipoInstrumento instTipo)
        {
            this.nombre = nombre;
            this.tipo = instTipo;
        }
    }
}
