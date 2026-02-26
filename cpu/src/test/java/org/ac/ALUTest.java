package org.ac;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

/**
 * Test suite for class ALU
 */
public class ALUTest extends Asserts {

    private final ALU alu = new ALU();

    @Test
    public void not() {
        Register r1 = new Register();
        Register r2 = new Register();

        r1.set(1);
        alu.not(r2, r1);
        assertRegister(r2, "1111 1110");
        assertEquals(r2.getInt(), -2);
    }

    @Test
    public void and() {
        assertAnd(alu, 3, 4, 0);
        assertFlags(alu, true, false, false, false);

        assertAnd(alu, 3, 3, 3);
        assertFlags(alu, false, false, false, false);

        assertAnd(alu, 255, 1, 1);
        assertFlags(alu, false, false, false, false);

        assertAnd(alu, 255, 255, 255);
        assertFlags(alu, false, false, true, false);
    }

    @Test
    public void lsl() {
        assertLsl(alu,1, 1, 2);
        assertFlags(alu, false, false, false, false);

        assertLsl(alu,1, 3, 8);
        assertFlags(alu, false, false, false, false);

        assertLsl(alu,-127, 1, 2);
        assertFlags(alu, false, true, false, true);

        assertLsl(alu,255, 1, -2);
        assertFlags(alu, false, true, true, false);

        assertLsl(alu,127, 1, -2);
        assertFlags(alu, false, false, true, true);
    }

    @Test
    public void add() {
        assertAdd(alu, 3, 4, 7);
        assertFlags(alu, false, false, false, false);

        assertAdd(alu, -63, 1, -62);
        assertFlags(alu, false, false, true, false);

        assertAdd(alu, 127, 1, -128);
        assertFlags(alu, false, false, true, true);

        assertAdd(alu, 127, 2, -127);
        assertFlags(alu, false, false, true, true);

        assertAdd(alu, -128, -1, 127);
        assertFlags(alu, false, true, false, true);

        assertAdd(alu, -4, 4, 0);
        assertFlags(alu, true, true, false, false);
    }
}
