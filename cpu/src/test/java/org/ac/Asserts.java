package org.ac;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;


/**
 * Utility class with assertions used in the project's unit tests.
 */
public class Asserts {

    protected static void assertRegister(Register register, String expected) {
        assertEquals(expected, register.toString());
    }

    protected static void assertRegister(Register register, int expected) {
        assertTrue(expected == register.getInt() || expected == register.getUnsignedInt());
    }

    protected static void assertRegister(FP32Register register, String expected) {
        assertEquals(expected, register.toString());
    }

    protected static void assertRegister(FP32Register register, float expected) {
        assertEquals(expected, register.get());
    }

    protected static void assertSet(Register register, int value, String expected) {
        register.set(value);
        assertRegister(register, expected);
    }

    protected static void assertGetInt(Register register, int value) {
        assertGetInt(register, value, value);
    }

    protected static void assertGetInt(Register register, int value, int expected) {
        register.set(value);
        assertEquals(expected, register.getInt());
    }

    protected static void assertGetUnsignedInt(Register register, int value) {
        assertGetUnsignedInt(register, value, value);
    }

    protected static void assertGetUnsignedInt(Register register, int value, int expected) {
        register.set(value);
        assertEquals(expected, register.getUnsignedInt());
    }

    protected static void assertAnd(ALU alu, int value1, int value2, int expected) {
        Register r1 = new Register();
        Register r2 = new Register();
        Register out = new Register();

        r1.set(value1);
        r2.set(value2);
        alu.and(out, r2, r1);
        assertRegister(out, expected);
    }

    protected static void assertAdd(ALU alu, int value1, int value2, int expected) {
        Register r1 = new Register();
        Register r2 = new Register();
        Register out = new Register();

        r1.set(value1);
        r2.set(value2);
        alu.add(out, r2, r1);
        assertRegister(out, expected);
    }

    protected static void assertLsl(ALU alu, int value, int n, int expected) {
        Register out = new Register();
        Register r = new Register();
        r.set(value);
        alu.lsl(out, r, n);
        assertRegister(out, expected);
    }

    protected static void assertFlags(ALU alu, boolean zero, boolean carry, boolean negative, boolean overflow) {
        assertEquals(zero, alu.zeroFlag());
        assertEquals(carry, alu.carryFlag());
        assertEquals(negative, alu.negativeFlag());
        assertEquals(overflow, alu.overflowFlag());
    }
}
