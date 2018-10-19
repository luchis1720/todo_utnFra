using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Estacionamiento
    {
        #region Fields

        private int espacioDisponible;
        private string nombre;
        private List<Vehiculo> vehiculos;

        #endregion

        #region Methods

        private Estacionamiento()
        {
            List<Vehiculo> vehiculos = new List<Vehiculo>();
        }

        public Estacionamiento(string nombre, int espacioDisponble)
        {
            this.nombre = nombre;
            this.espacioDisponible = espacioDisponble;
        }

        public static explicit operator string(Estacionamiento e)
        {
            string ans;
            StringBuilder sb = new StringBuilder();
            
            sb.AppendFormat("Estacionamiento: {0}", e.nombre);
            sb.AppendLine("");
            sb.AppendLine("Vehiculos");
            foreach (Vehiculo item in e.vehiculos)
                
            {
                sb.AppendLine(item.ConsultarDatos());
            }
            sb.AppendLine("");
            sb.AppendFormat("Espacios Disponibles: {0}", e.espacioDisponible);

            ans = sb.ToString();
            return ans;
        }

        public static bool operator ==(Estacionamiento estacionamiento, Vehiculo vehiculo)
        {
            foreach (Vehiculo item in estacionamiento.vehiculos)
            {
                if (object.Equals(item, vehiculo))
                {
                    return true;
                }
            }
            return false;
        }

        public static bool operator !=(Estacionamiento e, Vehiculo v)
        { 
            return !(e==v);
        }

        public static Estacionamiento operator +(Estacionamiento estacionamiento, Vehiculo vehiculo)
        {
            if (estacionamiento != vehiculo && estacionamiento.espacioDisponible > estacionamiento.vehiculos.Count && vehiculo.Patente!=null)
            {
                             
                    estacionamiento.vehiculos.Add(vehiculo);
                    return estacionamiento;
                
            }

            return estacionamiento;
        }

        public static string operator -(Estacionamiento estacionamiento, Vehiculo vehiculo)
        {
            string ans= "El Vehiculo no es parte del Estacionamiento";

            StringBuilder sb = new StringBuilder();


            foreach(Vehiculo item in estacionamiento.vehiculos)
            {
                if (vehiculo == item)
                {
                    sb.AppendLine(vehiculo.ImprimirTicket());
                    ans = sb.ToString();
                }
            }
            
            return ans;
        }

        #endregion
    }
}
