solver
======
A generic but stupid bruce-force solver. Debuggable in VSCode.

### Intended concepts
- define a problem (constraints, options, option effect, validation logic)

### TODOs
- [ ] nCr
- [ ] nPr
- [ ] filters
- Example
  - [x] Sorting
  - [ ] Sudoku
  - [ ] Tic-Tac-Toe
  - [ ] Scheduling
    - ```markdown
      ### this is a case where 1 nurse is enough (most even service time per each personnel, there nth more important than nth + 1 - nth personnel have pioripty picking time than nth+1, this is NOT order of time)
      - personnel A = 8 - 11 (3)
        personnel B = 9 - 1 (4)
        personnel C = 1 - 3 (2)
        
      - personnel health perspective
        - ```
          ABC(7, evenest) = 3 + 2 + 2
          ACB(7, evenest) = 3 + 2 + 2
          BAC(7) = 4 + 1 + 2
          BCA(7) = 4 + 2 + 1
          CAB(7, evenest) = 2 + 3 + 2
          CBA = 2 + 4 + 1
          ```

      - operation perspective (longest operation hour, there nth more important than nth + 1, this is order of time)
        - ```
          ABC(7, longest) = (8 - 11), (11 - 1), (1 - 3)
          ACB(5) = (8 - 11), (1 - 3), (-)
          BAC(6) = (9 - 1), (-), (1 - 3)
          BCA(6) = (9 - 1), (1 - 3), (-)
          CAB(2 = (1 - 3), (-), (-)
          CBA(2) = (1 - 3), (-), (-)
          ```
        - best sheduling should consider both perspective
      ```
