namespace VistaForm
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnCrear = new System.Windows.Forms.Button();
            this.lblpatente = new System.Windows.Forms.Label();
            this.lblModelo = new System.Windows.Forms.Label();
            this.txtPatente = new System.Windows.Forms.TextBox();
            this.txtModelo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btnCrear
            // 
            this.btnCrear.Location = new System.Drawing.Point(41, 121);
            this.btnCrear.Name = "btnCrear";
            this.btnCrear.Size = new System.Drawing.Size(186, 77);
            this.btnCrear.TabIndex = 0;
            this.btnCrear.Text = "Crear";
            this.btnCrear.UseVisualStyleBackColor = true;
            this.btnCrear.Click += new System.EventHandler(this.btnCrear_Click);
            // 
            // lblpatente
            // 
            this.lblpatente.AutoSize = true;
            this.lblpatente.Location = new System.Drawing.Point(41, 13);
            this.lblpatente.Name = "lblpatente";
            this.lblpatente.Size = new System.Drawing.Size(44, 13);
            this.lblpatente.TabIndex = 1;
            this.lblpatente.Text = "Patente";
            // 
            // lblModelo
            // 
            this.lblModelo.AutoSize = true;
            this.lblModelo.Location = new System.Drawing.Point(41, 67);
            this.lblModelo.Name = "lblModelo";
            this.lblModelo.Size = new System.Drawing.Size(42, 13);
            this.lblModelo.TabIndex = 2;
            this.lblModelo.Text = "Modelo";
            // 
            // txtPatente
            // 
            this.txtPatente.Location = new System.Drawing.Point(41, 30);
            this.txtPatente.Name = "txtPatente";
            this.txtPatente.Size = new System.Drawing.Size(186, 20);
            this.txtPatente.TabIndex = 3;
            // 
            // txtModelo
            // 
            this.txtModelo.Location = new System.Drawing.Point(44, 84);
            this.txtModelo.Name = "txtModelo";
            this.txtModelo.Size = new System.Drawing.Size(183, 20);
            this.txtModelo.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(258, 214);
            this.Controls.Add(this.txtModelo);
            this.Controls.Add(this.txtPatente);
            this.Controls.Add(this.lblModelo);
            this.Controls.Add(this.lblpatente);
            this.Controls.Add(this.btnCrear);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Crear PickUp";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnCrear;
        private System.Windows.Forms.Label lblpatente;
        private System.Windows.Forms.Label lblModelo;
        private System.Windows.Forms.TextBox txtPatente;
        private System.Windows.Forms.TextBox txtModelo;
    }
}

