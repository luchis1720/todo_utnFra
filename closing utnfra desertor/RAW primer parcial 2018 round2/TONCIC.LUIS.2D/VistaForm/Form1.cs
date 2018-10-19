using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace VistaForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Estacionamiento park = new Estacionamiento("UTN", 6);
        }

        private void btnCrear_Click(object sender, EventArgs e)
        {
            PickUp p1 = new PickUp(txtPatente.ToString(), txtModelo.ToString());
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Patente: {0} Modelo: { 1}", txtPatente.ToString(), txtModelo.ToString());
            MessageBox.Show(sb.ToString(), "CARGADO", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
}
