;;; Flores Lara Alberto; Luna Zamora Juan Antonio; Saucillo González Jesse Obed 	3BV2

(defun fibonacci (n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (t (+ (fibonacci (- n 1)) (fibonacci (- n 2))))))

(defun calcular-fibonacci ()
  (format t "Ingrese un número entero para calcular la serie de Fibonacci: ")
  (let ((numero (parse-integer (read-line))))
    (format t "Serie de Fibonacci para a:%" numero)
    (dotimes (i numero)
      (format t "Fib(a) = ~a%" i (fibonacci i)))
    (format t "Resultado final: a%" (fibonacci numero))))

(calcular-fibonacci)