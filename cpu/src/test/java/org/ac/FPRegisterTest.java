package org.ac;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

/**
 * Test suite for class FP32Register
 */
public class FPRegisterTest extends Asserts {

    @Test
    public void set() {
        FP32Register s0 = new FP32Register();
        s0.set(400);
        assertRegister(s0, "0 | 1000 0111 | 1001 0000 0000 0000 0000 000");
        s0.set(-400);
        assertRegister(s0, "1 | 1000 0111 | 1001 0000 0000 0000 0000 000");
        s0.set(0);
        assertRegister(s0, "0 | 0000 0000 | 0000 0000 0000 0000 0000 000");
        s0.set(-0.1f);
        assertRegister(s0, "1 | 0111 1011 | 1001 1001 1001 1001 1001 101");
    }

    @Test
    public void get() {
        FP32Register s0 = new FP32Register();
        s0.set(400);
        assertEquals(400, s0.get());
        s0.set(-400);
        assertEquals(-400, s0.get());
        s0.set(0);
        assertEquals(0, s0.get());
        s0.set(-0.1f);
        assertEquals(-0.1f, s0.get());
    }
}
