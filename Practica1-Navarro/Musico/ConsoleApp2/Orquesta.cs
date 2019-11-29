using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Orquesta
    {
        public string nombre;
        public string lugar;
        public TipoOrquesta tipo;
        public List<Musico> musicos;


        // como define dentro o fuera de la class es igual
        public enum TipoOrquesta {Sinfonica,Camara,Filarmonica}

        public Orquesta() { }

        //constructor con parametros
        public Orquesta(string nombre, string lugar, TipoOrquesta tipoOrquesta)
        {
            this.nombre = nombre;
            this.lugar = lugar;
            this.tipo = tipoOrquesta;
            this.musicos = new List<Musico>();
        }

        public string getOrquestaToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Nombre Orquesta: {}, Lugar{1},Tipo{2}\n",
                this.nombre, this.lugar, this.tipo);
            return sb.ToString();
        }

        public static void printOrquesta(Orquesta or)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(or.getOrquestaToString());
            if (or.musicos.Count > 0)
            {
                sb.AppendFormat("Lista Musicos\n");
                foreach(Musico element in or.musicos) //es como el for
                {
                    sb.AppendFormat("Musico: { 0}", element.nombre);
                    sb.AppendFormat("Musico: { 0}", element.nombre);
                }
            }
            else
            {
                sb.AppendFormat("No hay musicos en esta orquesta");
            }
            Console.WriteLine("{0}",sb.ToString());
            Console.ReadLine();//systemPause
        }
    }

            
}
