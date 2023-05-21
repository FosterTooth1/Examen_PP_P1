;;; Flores Lara Alberto; Luna Zamora Juan Antonio; Saucillo González Jesse Obed 	3BV2

(defun factorial (n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))

(defun calcular-factorial ()
  (format t "Ingrese un número entero para calcular su factorial: ")
  (let ((numero (parse-integer (read-line))))
    (format t "El factorial de a es: ~a%" numero (factorial numero))))

(calcular-factorial)