//Clientes

SubProceso agregarClientes(nombres, apellidos, ids, cantidad_clientes)
	Escribir "Ingrese el nombre del cliente:";
	Leer nombres[cantidad_clientes];
	Escribir "Ingrese el apellido del cliente:";
	Leer apellidos[cantidad_clientes];
	Escribir "Ingrese el ID del cliente:";
	Leer ids[cantidad_clientes];
	cantidad_clientes <- cantidad_clientes + 1;
	Escribir "Cliente agregado correctamente.";
FinSubProceso
	
SubProceso mostrarClientes(nombres, apellidos, ids, cantidad_clientes, i)
	Si cantidad_clientes == 0 Entonces
		Escribir "No hay clientes registrados.";
	Sino
		Escribir "Clientes registrados:";
		Para i <- 0 Hasta cantidad_clientes-1 Con Paso 1 Hacer
			Escribir "Nombre: ", nombres[i];
			Escribir "Apellido: ", apellidos[i];
			Escribir "ID: ", ids[i];
			Escribir "";
		FinPara
	FinSi
FinSubProceso

SubProceso editarCliente(nombres, apellidos, ids, cantidad_clientes, id_cliente)
	Definir i Como Entero;
	Definir Encontrado Como Logico;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingrese el ID del cliente a editar:";
	Leer id_cliente[contador1];
	Encontrado <- Falso;
	Para i <- 0 Hasta cantidad_clientes-1 Con Paso 1 Hacer
		Si ids[i] == id_cliente[contador1] Entonces
			Escribir "Ingrese el nuevo nombre del cliente:";
			Leer nombres[i];
			Escribir "Ingrese el nuevo apellido del cliente:";
			Leer apellidos[i];
			Escribir "Ingrese el nuevo ID del cliente:";
			Leer ids[i];
			Encontrado <- Verdadero;
			Escribir "Cliente editado correctamente.";
		FinSi
	FinPara
	Si Encontrado == Falso Entonces
		Escribir "No se encontró un cliente con el ID especificado.";
	FinSi
FinSubProceso

SubProceso eliminarCliente(nombres, apellidos, ids, cantidad_clientes, id_cliente)
	Definir i Como Entero;
	Definir Encontrado Como Logico;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingrese el ID del cliente a eliminar:";
	Leer id_cliente[contador1];
	Encontrado <- Falso;
	Para i <- 0 Hasta cantidad_clientes-1 Con Paso 1 Hacer
		Si ids[i] == id_cliente[contador1] Entonces
			nombres[i] <- "";
			apellidos[i] <- "";
			ids[i] <- "";
			Encontrado <- Verdadero;
			cantidad_clientes <- cantidad_clientes - 1;
			Escribir "Cliente eliminado correctamente.";
		FinSi
	FinPara
	Si Encontrado == Falso Entonces
		Escribir "No se encontró un cliente con el ID especificado.";
	FinSi
FinSubProceso

//Productos

SubProceso agregarProducto(producto, cantidad, idProducto, descripcion, precio, cantidad_productos)
	Escribir "Ingrese el nombre del producto:";
	Leer producto[cantidad_productos];
	Escribir "Ingrese la descripcion del producto:";
	Leer descripcion[cantidad_productos];
	Escribir "Ingrese el ID del producto:";
	Leer idProducto[cantidad_productos];
	Escribir "Ingrese la cantidad del producto:";
	Leer cantidad[cantidad_productos];
	Escribir "Dime el precio del producto:";
	Leer precio[cantidad_productos];
	cantidad_productos <- cantidad_productos + 1;
	Escribir "Producto agregado correctamente.";
FinSubProceso

SubProceso mostrarProductos(producto, cantidad, idProducto, descripcion, precio, cantidad_productos, i)
	Si cantidad_productos == 0 Entonces
		Escribir "No hay productos registrados.";
	Sino
		Escribir "Productos registrados:";
		Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
			Escribir "Nombre del producto: ", producto[i];
			Escribir "Descripcion del producto: ", descripcion[i];
			Escribir "ID del producto: ", idProducto[i];
			Escribir "Cantidad: ", cantidad[i];
			Escribir "Precio:", precio[i];
			Escribir "";
		FinPara
	FinSi
FinSubProceso

SubProceso editarProducto(producto, cantidad, idProducto, descripcion, precio, cantidad_productos, id_producto) 
	Definir i Como Entero;
	Definir Encontrado Como Logico;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingrese el ID del producto a editar:";
	Leer id_producto[contador1];
	Encontrado <- Falso;
	Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
		Si idProducto[i] == id_producto[contador1] Entonces
			Escribir "Ingresa el nuevo nombre del producto:";
			Leer producto[i];
			Escribir "Ingrese la nueva descripcion del producto:";
			Leer descripcion[i];
			Escribir "Ingrese el nuevo ID del producto:";
			Leer idProducto[i];
			Escribir "Ingrese la nueva cantidad de producto:";
			Leer cantidad[i];
			Escribir "Ingrese el nuevo precio del producto:";
			Leer precio[i];
			Encontrado <- Verdadero;
			Escribir "Producto eliminado correctamente.";
		FinSi
	FinPara
	Si Encontrado == Falso Entonces
		Escribir "No se encontró el producto con el ID especificado.";
	FinSi
FinSubProceso

SubProceso eliminarProducto(producto, cantidad, idProducto, descripcion, precio, cantidad_productos, id_producto) 
	Definir i Como Entero;
	Definir Encontrado Como Logico;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingrese el ID del producto a eliminar:";
	Leer id_producto[contador1];
	Encontrado <- Falso;
	Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
		Si idProducto[i] == id_producto[contador1] Entonces
			producto[i] <- "";
			descripcion[i] <- "";
			idProducto[i] <- "";
			cantidad[i] <- "";
			precio[i] <- "";
			Encontrado <- Verdadero;
			cantidad_productos <- cantidad_productos - 1;
			Escribir "Producto eliminado correctamente.";
		FinSi
	FinPara
	Si Encontrado == Falso Entonces
		Escribir "No se encontró el producto con el ID especificado.";
	FinSi
FinSubProceso

//usuarios

SubProceso agregarUsuario(usuario, idUsuario, password, cantidad_usuarios)
	Escribir "Nombre del usuario: ";
	Leer usuario[cantidad_usuarios];
	Escribir "Ingrese su ID: ";
	Leer idUsuario[cantidad_usuarios];
	Escribir "Ingrese su contraseña";
	Leer password[cantidad_usuarios];
	Escribir "Ingrese la cantidad de usuarios";
	cantidad_usuarios <- cantidad_usuarios + 1;
	Escribir "Usuario agregado correctamente.";
FinSubProceso

SubProceso mostrarUsuarios(usuario, idUsuario, password, cantidad_usuarios, i)
	Si cantidad_usuarios == 0 Entonces
		Escribir "No hay usuario registrados.";
	Sino
		Escribir "Usuario registrados:";
		Para i <- 0 Hasta cantidad_usuarios-1 Con Paso 1 Hacer
			Escribir "Nombre de usuario: ", usuario[i];
			Escribir "ID del usuario: ", idUsuario[i];
			Escribir "Contraseña: ", password[i];
			Escribir "";
		FinPara
	FinSi
FinSubProceso

SubProceso editarUsuario(usuario, idUsuario, password, cantidad_usuarios, id_usuario) 
	Definir i Como Entero;
	Definir Encontrado Como Logico;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingrese el ID del usuario a editar:";
	Leer id_usuario[contador1];
	Encontrado <- Falso;
	Para i <- 0 Hasta cantidad_usuarios-1 Con Paso 1 Hacer
		Si idUsuario[i] == id_usuario[contador1] Entonces
			Escribir "Ingresa el nuevo nombre de usuario:";
			Leer usuario[i];
			Escribir "Ingrese el nuevo ID de usuario:";
			Leer idUsuario[i];
			Escribir "Ingrese la password de usuario:";
			Leer password[i];
			Encontrado <- Verdadero;
			Escribir "Usuario editado correctamente.";
		FinSi
	FinPara
	Si Encontrado == Falso Entonces
		Escribir "No se encontró el usuario con el ID especificado.";
	FinSi
FinSubProceso

SubProceso eliminarUsuario(usuario, idUsuario, password, cantidad_usuarios, id_usuario) 
	Definir i Como Entero;
	Definir Encontrado Como Logico;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingrese el ID del usuario a eliminar:";
	Leer id_usuario[contador1];
	Encontrado <- Falso;
	Para i <- 0 Hasta cantidad_usuarios-1 Con Paso 1 Hacer
		Si idUsuario[i] == id_usuario[contador1] Entonces
			usuario[i] <- "";
			idUsuario[i] <- "";
			password[i] <- "";
			Encontrado <- Verdadero;
			cantidad_usuarios <- cantidad_usuarios - 1;
			Escribir "Usuario eliminado correctamente.";
		FinSi
	FinPara
	Si Encontrado == Falso Entonces
		Escribir "No se encontró el producto con el ID especificado.";
	FinSi
FinSubProceso

//facturas

SubProceso encabezadoFactura(cantidad_facturas, cliente, fecha)
	Escribir "===============Bienvenido a MCSerigraph===============";
	Escribir "Direccion: Masaya";
    Escribir "Telefono: 25613023";
	Escribir "Factura #: ", cantidad_facturas;
    Escribir "Fecha: ", fecha[cantidad_facturas];
    Escribir "======================================================";
    Escribir "Cliente: ", cliente[cantidad_facturas];
FinSubProceso

SubProceso pieDeFactura()
	Escribir "======================================================";
	Escribir "Gracias por su compra";
	Escribir "======================================================";
FinSubProceso

SubProceso imprimirDetalle(cantidad_facturas, cliente, fecha, cantidadTemporal, precioTemporal, montoTemporal, totalTemporal, producto, cantidad, idProducto, descripcion, precio, cantidad_productos, id_producto)
	Definir i Como Entero;
	Definir j Como Entero;
	Definir cantidadProductFactura Como Entero;
	cantidadProductFactura <- 0;
	Definir contador1 Como Entero;
	contador1<-1;
	
	Escribir "Ingresa la fecha: ";
	Leer fecha[cantidad_facturas];
	Escribir "Ingresa el cliente: ";
	Leer cliente[cantidad_facturas];
	
	encabezadoFactura(cantidad_facturas, cliente, fecha);
	
	Escribir "Cuantos productos desea facturar?";
	Leer cantidadProductFactura;
	Para j <- 0 Hasta cantidadProductFactura-1 Con Paso 1 Hacer
		Escribir "Ingrese el ID del producto:";
		Leer id_producto[contador1];
		Para i <- 0 Hasta cantidad_productos-1 Con Paso 1 Hacer
			Si idProducto[i] == id_producto[contador1] Entonces
				Escribir producto[i];
				Escribir precio[i];
			FinSi
		FinPara
	FinPara
	pieDeFactura();
FinSubProceso



//pricipal

Proceso proyectoFinal
	Definir nombres, apellidos, ids Como Caracter;
    Dimension nombres[50], apellidos[50], ids[50];
	
	Definir producto, cantidad, idProducto, descripcion, precio Como Caracter;
    Dimension producto[50], cantidad[50], idProducto[50], descripcion[50], precio[50];
	
	Definir id_cliente, id_producto, id_usuario Como Caracter;
	Dimension id_cliente[50], id_producto[50], id_usuario[50];
	
	Definir usuario, idUsuario, password Como Caracter;
    Dimension usuario[50], idUsuario[50], password[50];
	
    Definir cantidad_clientes, cantidad_productos, cantidad_usuarios, cantidad_facturas Como Entero;
	Definir opcion Como Entero;
	
	Definir fecha, cliente Como Caracter;
	Dimension fecha[15], cliente[50];
	
	Definir EncontradoDelCliente Como Logico;
	
	Definir cantidadTemporal, precioTemporal, montoTemporal, totalTemporal Como Real;
	cantidadTemporal <- 0;
	precioTemporal <- 0;
	montoTemporal <- 0;
	totalTemporal <- 0;
	
	cantidad_productos <- 0;
    cantidad_clientes <- 0;
	cantidad_usuarios <- 0;
	cantidad_facturas <- 0;
    opcion <- 0;
	
	Definir i, j Como Entero;
	i <- 0;
	j <- 0;
	
	
	Repetir
		Escribir " ";
		Escribir "===============Bienvenido a MCSerigraph===============";
        Escribir "Elija una opción:";
		Escribir "Clientes...";
        Escribir "1. Agregar cliente";
        Escribir "2. Mostrar clientes";
		Escribir "3. Editar cliente";
		Escribir "4. Eliminar cliente";
		Escribir "Productos...";
        Escribir "5. Agregar productos";
		Escribir "6. Mostrar productos";
		Escribir "7. Editar productos";
		Escribir "8. Eliminar productos";
		Escribir "Usuarios...";
		Escribir "9. Agregar usuarios";
		Escribir "10. Mostrar usuarios";
		Escribir "11. Editar usuarios";
		Escribir "12. Eliminar usuarios";
		Escribir "Facturas...";
		Escribir "13. Generar factura...";
		Escribir "Salir del programa...";
		Escribir "20. Salir.";
        Leer opcion;
	
		Segun opcion Hacer
			1:
				agregarClientes(nombres, apellidos, ids, cantidad_clientes);
				cantidad_clientes <- cantidad_clientes + 1;
			2:
				mostrarClientes(nombres, apellidos, ids, cantidad_clientes, i);
				
			3: 
				editarCliente(nombres, apellidos, ids, cantidad_clientes, id_cliente);
			4:
				eliminarCliente(nombres, apellidos, ids, cantidad_clientes, id_cliente);
			5:
				agregarProducto(producto, cantidad, idProducto, descripcion, precio, cantidad_productos);
				cantidad_productos <- cantidad_productos + 1;
			6:
				mostrarProductos(producto, cantidad, idProducto, descripcion, precio, cantidad_productos, i);
			7:
				editarProducto(producto, cantidad, idProducto, descripcion, precio, cantidad_productos, id_producto);
			8:
				eliminarProducto(producto, cantidad, idProducto, descripcion, precio, cantidad_productos, id_producto);
			9:
				agregarUsuario(usuario, idUsuario, password, cantidad_usuarios);
				cantidad_usuarios<-cantidad_usuarios+1;
			10:
				mostrarUsuarios(usuario, idUsuario, password, cantidad_usuarios, i);
			11:
				editarUsuario(usuario, idUsuario, password, cantidad_usuarios, id_usuario);
			12:
				eliminarUsuario(usuario, idUsuario, password, cantidad_usuarios, id_usuario);
			13:
				imprimirDetalle(cantidad_facturas, cliente, fecha, cantidadTemporal, precioTemporal, montoTemporal, totalTemporal, producto, cantidad, idProducto, descripcion, precio, cantidad_productos, id_producto);
			20:	Escribir "Saliendo del programa...";
			De Otro Modo:
				Escribir "Opción inválida. Inténtalo de nuevo.";
		FinSegun
	Hasta Que opcion == 20;
	
	
FinProceso

