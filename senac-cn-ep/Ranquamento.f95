!gfortran PageRank.f95 -o main

PROGRAM Ranqueamento
    implicit none
    double precision, dimension(4,4) :: A
    double precision, dimension(:), allocatable :: V

    A(1,1) = 0
    A(2,1) = 0
    A(3,1) = 1
    A(4,1) = 1/2.0

    A(1,2) = 1/3.0
    A(2,2) = 0
    A(3,2) = 0
    A(4,2) = 0

    A(1,3) = 1/3.0
    A(2,3) = 1/2.0
    A(3,3) = 0
    A(4,3) = 1/2.0

    A(1,4) = 1/3.0
    A(2,4) = 1/2.0
    A(3,4) = 0
    A(4,4) = 0

    V = calcRank(A)

    print *, V

    contains
    function calcRank(A)
        double precision, dimension(:, :) :: A
        real :: x, m
        integer :: n, i, j, counter
        double precision, dimension (:), allocatable :: calcRank, sm
        double precision :: before, precision

        !m = google
        m = 0.15

        !igualando before a 1 para entrar no looping com a condição de parada e setando precisão
        before = 1
        precision = 0.0005
        counter = 0

        !obtendo n da matriz n x n, e alocando no vetor de pesos
        x = size(A)
        n = sqrt(x)
        allocate(calcRank(n))
        allocate(sm(n))

        !multiplicando a matriz A pelo (1-m): pedido no EP
        do i = 1, n
            do j = 1, n
                a(i,j) = A(i, j) * (1 - m)
            enddo
        enddo

        !criando vetor de pesos
        do i = 1, n
            calcRank(i) = 1.0/n
            sm(i) = (1.0/n) * m 
        enddo

        !Condição de parada para o calculo dos pesos
        do while(abs(before - calcRank(1)) > precision)
            before = calcRank(1)

            !(1-m)Ay
            calcRank = MATMUL(A, calcRank)

            !(1-m)Ay + sm
            do j = 1, n
                calcRank(j) = calcRank(j) + sm(j)
            enddo
            counter = counter + 1
        enddo


    end function

END PROGRAM Ranqueamento