package org.ac;

/**
 * Class that models a 32-bit floating point register in IEEE 754 format.
 */
public class FP32Register {

    /**
     * Size of the register
     */
    private static final int FP32_REGISTER_SIZE = 32;

    /**
     * Contents of the register
     */
    final boolean[] bits = new boolean[FP32_REGISTER_SIZE];


    /**
     * Stores the given value in IEEE 754 32-bit format.
     */
    public void set(float value) {
        // TODO
    }

    /**
     * Returns the register contents as a float.
     */
    public float get() {
        // TODO
        float todo = 0;
        return todo;
    }

    /**
     * Returns a string in the format \texttt{<S> | <exp> | <mant>}, where exponent and mantissa are grouped in blocks
     * of 4 bits separated by spaces.
     */
    @Override
    public String toString() {
        // TODO
        return "TODO";
    }
}
